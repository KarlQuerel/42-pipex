/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:59:00 by kquerel           #+#    #+#             */
/*   Updated: 2023/07/14 19:03:54 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/* UTILS.C */
void	ft_putstr(char *str);
void	ft_exit(int exit_code);
int	ft_open(char *file, char *which_file);
#endif
