/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karl <karl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:59:00 by kquerel           #+#    #+#             */
/*   Updated: 2023/07/17 18:05:52 by karl             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PIPEX_H
# define PIPEX_H
#define LEN_PATH 5

#include "../libft/libft.h"
#include <errno.h>
#include <sys/wait.h>

/* Structure */
typedef struct s_pipex
{
	pid_t pid;
	int	pipefd[2];
	
	int	infile_fd;
	int	outfile_fd;
	int	cmd_count;
	char	**cmd_paths;
	char	**cmd_args;
}	t_pipex;

/* MAIN.C */
void	ft_parent(char **av, char **envp, int *pipefd);
void	ft_child(char **av, char **envp, int *pipefd);

/* UTILS.C */
void	ft_putstr(char *str);
void	ft_exit(char *error);
char	**ft_get_path(char **envp);
char	*ft_get_command(char **paths, char *command);
#endif
