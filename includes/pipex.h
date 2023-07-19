/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:59:00 by kquerel           #+#    #+#             */
/*   Updated: 2023/07/19 15:07:51 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
#define LEN_PATH 5

#include "../libft/libft.h"
#include <errno.h>
#include <stdbool.h>
#include <sys/wait.h>

/* Structure */
typedef struct s_pipex
{
	pid_t	pid_child1;
	pid_t	pid_child2;
	int	pipe_end[2];
	int	fd_infile;
	int	fd_outfile;
	char	**argument;
	char	*command;
}	t_pipex;

/* MAIN.C */
// void	ft_parent(char **av, char **envp, t_pipex data);
// void	ft_child(char **av, char **envp, t_pipex data);

// /* UTILS.C */
// void	ft_free(t_pipex data, int trigger);
// void	ft_exit(char *error);
// char	**ft_get_path(char **envp);
// char	*ft_get_command(char **paths, char *command);
// int	ft_open(char **av, int trigger);
#endif
