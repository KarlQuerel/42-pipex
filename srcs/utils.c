/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:55:33 by kquerel           #+#    #+#             */
/*   Updated: 2023/07/21 14:42:58 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* Handles file opening */
int	ft_open(char **av, int trigger)
{
	int	fd_open;

	if (trigger == 0)
		fd_open = open(av[1], O_RDONLY);
	if (trigger == 1)
		fd_open = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_open < 0)
	{
		perror("Error");
		exit(1);
	}
	return (fd_open);
}

/* Extracts command from argv and verify if they are valid */
char	*ft_get_command(char **path, char *argument)
{
	char	*to_free;
	char	*to_return;
	int		i;

	i = 0;
	while (path[i])
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
	int		i;
	char	**path_split;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", LEN_PATH) == 0)
			path_split = ft_split(envp[i] + LEN_PATH, ':');
		i++;
	}
	if (path_split == NULL)
		return (NULL);
	return (path_split);
}
