/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:57:36 by kquerel           #+#    #+#             */
/*   Updated: 2023/07/21 15:43:05 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* Initiates fork on both children */
void ft_init_fork(t_pipex *data, int trigger)
{
	if (trigger == 1)
	{
		data->pid_child1 = fork();
		if (data->pid_child1 < 0)
		{
			perror("Error");
			exit(1);
		}
	}
	else if (trigger == 2)
	{
		data->pid_child2 = fork();
		if (data->pid_child2 < 0)
		{
			perror("Error");
			exit(1);
		}
	}
}

/* First child */
void ft_first_child(char **av, char **envp, t_pipex *data)
{
	data->fd_infile = ft_open(av, 0);
	dup2(data->fd_infile, 1);
	dup2(data->pipe_end[1], 1);
	close(data->pipe_end[0]);
	data->argument = ft_split(av[2], ' ');
	if (!data->argument[0])
	{
		free(data->argument); // pas sur
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	data->path = ft_get_path(envp);
	data->command = ft_get_command(data->path, data->argument[0]);
	if (data->command == NULL)
	{
		ft_free(data, 0);
		perror("Error");
		exit(1);
	}
	execve(data->command, data->argument, envp);
}

/* Second child */
void ft_second_child(char **av, char **envp, t_pipex *data)
{
	data->fd_outfile = ft_open(av, 1);
	dup2(data->fd_outfile, 0);
	dup2(data->pipe_end[0], 0);
	close(data->pipe_end[1]);
	data->argument = ft_split(av[3], ' ');
	if (!data->argument[0])
	{
		free(data->argument); // pas sur
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	data->path = ft_get_path(envp);
	data->command = ft_get_command(data->path, data->argument[0]);
	if (data->command == NULL)
	{
		ft_free(data, 0);
		perror("Error");
		exit(1);
	}
	execve(data->command, data->argument, envp);
}

/* Free memory */
void ft_free(t_pipex *data, int trigger)
{
	int i;

	i = 0;
	if (trigger == 0)
	{
		while (data->argument[i])
		{
			free(data->argument[i]);
			i++;
		}
		free(data->command);
		free(data->argument);
	}
	if (trigger == 1)
	{
		i = 0;
		close(data->fd_infile);
		close(data->fd_outfile);
		// printf("---path[%d] = \n", i /*, data->path[i] */); //seg fault ici
		// while (data->path[i])
		// {
		// 	free(data->path[i]);
		// 	i++;
		// }
		// free(data->path);
	}
}
/* Main */
int main(int ac, char **av, char **envp)
{
	t_pipex data;

	if (ac != 5)
		return (ft_putstr_fd("Error\nInvalid number of arguments\n", 2), 1);
	if (pipe(data.pipe_end) < 0)
		return (perror("Error"), 1);
	ft_init_fork(&data, 1);
	if (data.pid_child1 == 0)
		ft_first_child(av, envp, &data);
	ft_init_fork(&data, 2);
	if (data.pid_child2 == 0)
		ft_second_child(av, envp, &data);
	close(data.pipe_end[0]);
	close(data.pipe_end[1]);
	waitpid(data.pid_child1, NULL, 0);
	waitpid(data.pid_child2, NULL, 0);
	ft_free(&data, 1);
	return (0);
}
