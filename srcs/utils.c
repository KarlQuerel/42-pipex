/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karl <karl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:55:33 by kquerel           #+#    #+#             */
/*   Updated: 2023/07/17 19:30:43 by karl             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/pipex.h"

void	functionname(int c)
{
	
}

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
void	ft_exit(char *error)
{
	ft_putstr_fd(error, 2);
	exit(0);
}

/*  */
// void	ft_execve(char *file, int fd)
// {
	
// }

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
	return (path_split)
}

/* */
char	*ft_get_command(char **paths, char *command)
{
	
}