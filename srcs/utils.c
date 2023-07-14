/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:55:33 by kquerel           #+#    #+#             */
/*   Updated: 2023/07/14 19:06:26 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* Classic good ol' put_str */
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

/* Handles exit behavior */
void	ft_exit(int exit_code)
{
	// MAYBE USE PUTSTRFD IS BETTER, to check!
	
	if (exit_code == 0)
		ft_putstr("Error!\nInvalid number of arguments\n");
	else if (exit_code == 1)
		ft_putstr("Error!\nPipe failed\n");
	else if (exit_code == 2)
		ft_putstr("Error!\nFork failed\n");
	else if (exit_code == 3)
		ft_putstr("Error!\nOpen failed\n");
	exit(0);
}

/* Open files and return file descriptor */
int	ft_open(char *file, char *which_file)
{
	int	open_fd;

	if (which_file == "infile") //infile
		open_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (which_file == "outfile") //outfile
		open_fd = open(file, O_RDONLY, 0777);
	if (open_fd == -1) //error
		ft_exit(3);
	return (open_fd);
}

/*  */
// void	ft_execve(char *file, int fd)
// {
	
// }

/*  */
void	ft_get_env(char **envp)
{
	int	i;
	char **path_split;

	i = 0;
	while (envp[i])
	{
		printf("envp[%d] = %s\n", i, envp[i]);
		if (ft_strncmp(envp[i], "PATH=", LEN_PATH) == 0)
			path_split = ft_split(envp[i] + LEN_PATH, ':');
		i++;
	}
	// ---- TO PRINT
	// i = 0;
	// while (path_split[i])
	// {
	// 	printf("%s\n", path_split[i]);
	// 	i++;
	// }
}