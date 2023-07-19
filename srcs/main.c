/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:57:36 by kquerel           #+#    #+#             */
/*   Updated: 2023/07/19 18:59:16 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* Extracts command from argv and verify if they are valid */
char	*ft_get_command(char **path, char *argument)
{
	char	*to_free;
	char	*to_return;
	int	i;

	i = 0;
	while(path[i])
	{
		to_free = ft_strjoin(path[i], "/");
		to_return = ft_strjoin(to_free, argument);
		free(to_free);
		if (access(to_return, 0) == 0)
			return (to_return);
		free(to_return);
		i++;
	}
	return (NULL);
}

/* Extracts commands path from the environment */
char	**ft_get_path(char **envp)
{
	int	i;
	char **path_split;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", LEN_PATH) == 0)
			path_split = ft_split(envp[i] + LEN_PATH, ':');
		i++;
	}
	if(path_split == NULL)
		return (NULL);
	return (path_split);
}


/* Handles file opening */
int	ft_open(char **av, int trigger)
{
	int	fd_open;
	
	if (trigger == 0)
		fd_open = open(av[1], O_RDONLY);
	if (trigger == 1)
		fd_open = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_open < 0)
		perror("Error"), exit(1);
	return (fd_open);
}

/* First child */
void	ft_first_child(char **av, char **envp, t_pipex *data)
{
	data->fd_infile = ft_open(av, 0);
	dup2(data->pipe_end[1], 1);
	close(data->pipe_end[0]);
	dup2(data->fd_infile, 0);
	data->argument = ft_split(av[2], ' ');
	if (!data->argument[0])
		ft_putstr_fd("Error\nSplit failed!\n", 2), exit (1);
	data->command = ft_get_command(ft_get_path(envp), data->argument[0]);
	if (data->command == NULL)
	{
		perror("Error");
		exit(1);
	}
	execve(data->command, data->argument, envp);
}

/* Second child */
void	ft_second_child(char **av, char **envp, t_pipex *data)
{
	data->fd_outfile = ft_open(av, 1);
	dup2(data->pipe_end[0], 0);
	close(data->pipe_end[1]);
	dup2(data->fd_outfile, 1);
	data->argument = ft_split(av[3], ' ');
	if (!data->argument[0])
		ft_putstr_fd("Error\nSplit failed!\n", 2), exit (1);
	data->command = ft_get_command(ft_get_path(envp), data->argument[0]);
	if (data->command == NULL)
	{
		perror("Error");
		exit(1);
	}
	execve(data->command, data->argument, envp);
}

/* Initiates fork on both children */
void	ft_init_fork(t_pipex *data, int trigger)
{
	if (trigger == 1)
	{
		data->pid_child1 = fork();
		printf("child1 = %d\n", data->pid_child1);
		if (data->pid_child1 < 0)
			perror("Error"), exit(1);
	}
	else if (trigger == 2)
	{
		data->pid_child2 = fork();
		if (data->pid_child2 < 0)
			perror("Error"), exit(1);
	}
}

/* Main */
int	main(int ac, char **av, char **envp)
{

	t_pipex	data;
	
	if (ac != 5)
		return (ft_putstr_fd("Error\nInvalid number of arguments\n", 2), 1);
	if (pipe(data.pipe_end) < 0)
		return (perror("Error"), 1);
	ft_init_fork(&data, 1);
	if (data.pid_child1 == 0)
		ft_first_child(av, envp, &data);
	ft_init_fork(&data, 2);
	if (data.pid_child2 ==  0)
		ft_second_child(av, envp, &data);
	close(data.pipe_end[0]);
	close(data.pipe_end[1]);
	waitpid(data.pid_child1, NULL, 0);
	waitpid(data.pid_child2, NULL, 0); // ca tourne en boucle
	// free parent
	return (0);
}

// /* Child function */
// void	ft_child(char **av, char **envp, t_pipex data)
// {
// 	dup2(data.fd_infile, 1);
// 	dup2(data.pipe_end[1], 1);
// 	close(data.pipe_end[0]);
// 	data.argument = ft_split(av[2], ' ');
// 	data.command = ft_get_command(ft_get_path(envp), data.argument[0]);
// 	if (data.command == NULL)
// 	{
// 		ft_free(data, 0);
// 		exit(0);
// 	}
// 	execve(data.command, data.argument, envp);
// }

// /* Parent function */
// void	ft_parent(char **av, char **envp, t_pipex data)
// {
// 	dup2(data.fd_outfile, 0);
// 	dup2(data.pipe_end[0], 0);
// 	close(data.pipe_end[1]);
// 	data.argument = ft_split(av[3], ' ');
// 	data.command = ft_get_command(ft_get_path(envp), data.argument[0]);
// 	if (data.command == NULL)
// 	{
// 		ft_free(data, 1);
// 		exit(0);
// 	}
// 	execve(data.command, data.argument, envp);
// }

	
	
	
	
	
	
	
	
// 	data.fd_infile = ft_open(av, 0);
// 	data.fd_outfile = ft_open(av, 1);
// 	if (pipe(data.pipe_end) == -1)
// 		ft_exit("Pipe failed\n");
// 	data.pid = fork();
// 	if (data.pid == -1)
// 		ft_exit("Fork failed\n");
// 	if (data.pid > 0)
// 		ft_parent(av, envp, data);
// 	if (data.pid == 0)
// 		ft_child(av, envp, data);
// 	waitpid(data.pid, NULL, 0); // a regarder en detail
// 	return (0);
// }
// ./pipex infile ls grep outile
// 	 0	   1	  2	 3	  4