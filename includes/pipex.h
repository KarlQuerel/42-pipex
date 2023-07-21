/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:59:00 by kquerel           #+#    #+#             */
/*   Updated: 2023/07/21 19:14:34 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# ifndef LEN_PATH
#  define LEN_PATH 5

# endif

# include "../libft/libft.h"
# include <errno.h>
# include <stdbool.h>
# include <sys/wait.h>

/* Structure */
typedef struct s_pipex
{
	pid_t	pid_child1;
	pid_t	pid_child2;
	int		pipe_end[2];
	int		fd_infile;
	int		fd_outfile;
	char	**argument;
	char	**path;
	char	*command;
}	t_pipex;

/* MAIN.C */
void	ft_init_fork(t_pipex *data, int trigger);
void	ft_first_child(char **av, char **envp, t_pipex *data);
void	ft_second_child(char **av, char **envp, t_pipex *data);
void	ft_free(t_pipex *data, int trigger);

// /* UTILS.C */
int		ft_open(char **av, int trigger);
char	*ft_get_command(char **path, char *argument);
char	**ft_get_path(char **envp);
void	ft_close(t_pipex *data, int trigger);
void	ft_exec_ve(t_pipex *data, char **envp);

#endif