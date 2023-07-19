/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:55:33 by kquerel           #+#    #+#             */
/*   Updated: 2023/07/19 16:51:54 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* Handles exit behavior */
void	ft_exit(char *error)
{
	ft_putstr_fd(error, 2);
	exit(0);
}

/* Extracts commands path from the environment */
char	**ft_get_path(char **envp)
{
	int	i;
	char **path_split;

	i = 0;
	*path_split = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", LEN_PATH) == 0)
			path_split = ft_split(envp[i] + LEN_PATH, ':');
		i++;
	}
	return (path_split);
}

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

/* Handles free behavior */
void	ft_free(t_pipex data, int trigger)
{
	int	i;

	i = 0;
	if (trigger == 0)
	{
		while (data.argument[i])
		{
			free(data.argument[i]);
			i++;
		}
		free(data.argument);
		free(data.command);
	}
	i = 0;
	if (trigger == 1)
	{
		close(data.fd_infile);
		close(data.fd_outfile);
		// while(data.)
	}
}

/* Opens infile or outfile depending on trigger */
int	ft_open(char **av, int trigger)
{
	int	fd_open;

	if (trigger == 0)
		fd_open = open(av[1], O_RDONLY);
	if (trigger == 1)
		fd_open = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_open == -1)
		ft_exit("Open failed\n");
	return (fd_open);
}
