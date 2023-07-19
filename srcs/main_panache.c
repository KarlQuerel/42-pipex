/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_panache.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:43:24 by kquerel           #+#    #+#             */
/*   Updated: 2023/07/19 18:22:46 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

bool	ft_open_infile(int	*fd, char *file)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		return (false);// utiliser perror
	return (true);
}

bool	ft_open_outfile(int	*fd, char *file)
{
	*fd = open(file, O_WRONLY | O_CREAT | O_TRUNC);
	if (*fd < 0)
		return (false);// utiliser perror
	return (true);
}

bool	ft_open(int i, char **argv, int	fds[2])
{
	if (!i)
		return (ft_open_infile(&(fds[0]), argv[1]));
	else
		return (ft_open_outfile(&(fds[1]), argv[4]));
}


/* Extracts commands path from the environment */
// on peut retourner NULL soit si malloc de split echoue soit si on trouve pas de PATH=
bool	ft_get_path(char **envp, char ***path_split)
{
	int	i;

	i = 0;
	*path_split = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", LEN_PATH) == 0)
		{
			*path_split = ft_split(envp[i] + LEN_PATH, ':');
			if (!*path_split)
				return (false);
		}
		i++;
	}
	return (true);
}

void	ft_free_strs(char **strs)
{
	int	i;

	if (strs)
	{
		i = 0;
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
	}
}

// trigger 0 -> on ne free rien
// trigger 1 -> free le left
// trigger 2 -> free le right
// trigger 3 -> free le left et le right
bool	ft_strjoin_des_familles(char **pablo, char *left, char *right, int trigger)
{
	int len_left;
	int len_right;

	if (!left || !right)
		return (true);
	len_left = ft_strlen(left);
	len_right = ft_strlen(right);
	*pablo = malloc(len_left + len_right + 1);
	if (!*pablo)
		return (false);
	ft_memcpy(*pablo, left, len_left);
	ft_memcpy(*pablo + len_left, left, len_right + 1);
	if (trigger & 1)
		free(left);
	if (trigger & 2)
		free(right);
	return (true);
}

/* Extracts command from argv and verify if they are valid */
bool	ft_get_command(char **paths_possible, char **path_return, char *arg)
{
	int	i;

	i = 0;
	if (paths_possible)
	{
		while(paths_possible[i])
		{
			if (!ft_strjoin_des_familles(path_return, paths_possible[i], "/", 0))
				return (false);
			if (!ft_strjoin_des_familles(path_return, *path_return, arg, 1))
				return (false);
			if (access(*path_return, 0) == 0)
				return (true);
			free(path_return);
			i++;
		}
	}
	return (true);
}

void	ft_execve(int i, char **argv, char **env)
{
	char	**cmd;
	char	**paths;
	char	*path;

	if (!ft_get_path(env, &paths))
		(ft_putstr_fd("allocation failed\n", 2), exit(1));
	cmd = ft_split(argv[2 + i], ' ');
	if (!cmd)
		(ft_free_strs(paths), ft_putstr_fd("allocation failed\n", 2), exit(1));
	if (ft_strchr(cmd[0], '/'))
		execve(cmd[0], cmd, env);
	else
	{
		if (!ft_get_command(paths, &path, cmd[0]))
		{
			(ft_free_strs(cmd), ft_free_strs(paths));
			ft_putstr_fd("allocation failed\n", 2);
			exit(1);
		}
		execve(path, cmd, env);
	}
	ft_free_strs(cmd);
	ft_free_strs(paths);
	ft_putstr_fd("cannot found cmd\n", 2);
	exit(127); // pour le minishell NOTES KARL echo $? pour voir le dernier exit status
}
bool	ft_dup2(int i, int fds[2], int pipe[2])
{
	if (!i) // first child
	{
		dup2(fds[0], 0); //fd infile
		close(fds[0]);
		dup2(pipe[1], 1);
	}
	else // second child
	{
		dup2(pipe[0], 0); // fd outfile
		dup2(fds[1], 1);
		close(fds[1]);
	}
	close(pipe[0]);
	close(pipe[1]);
	return (true);
}

void    ft_child(int i, char **argv, char **env, int pipe[2])
{
	int	fds[2];

	if (!ft_open(i, argv, fds)) // fd[0]; fd[1];
		exit (1);
	if (!ft_dup2(i, fds, pipe))
		exit (1);
	ft_execve(i, argv, env);
}

int main(int argc, char **argv, char **env)
{
	int		i;
	int		pip[2];
	pid_t	last_pid;

	if (argc != 5)
		return (write(2, "Error!\n", 7), 1);
	i = 0;
	if (pipe(pip) < 0)
		return (ft_putstr_fd("Aaaaalbannnn!\n", 2), 1);
	while (i < 2)
	{
		last_pid = fork();
		if (last_pid < 0)
			return (ft_putstr_fd("Aaaaalbannnn!\n", 2), 1);
		else if (last_pid == 0)
			ft_child(i, argv, env, pip);
		i++;
	}
	close(pip[0]);
	close(pip[1]);
    return (0);
}
