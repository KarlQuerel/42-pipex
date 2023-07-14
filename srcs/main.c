/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:57:36 by kquerel           #+#    #+#             */
/*   Updated: 2023/07/14 19:06:00 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* Pipe function */
/* void	ft_pipe(int fd_read, int fd_write)
{
	int	pipes[2];

	pipe(pipes);
} */

/* Child function */
void	ft_child(char **av, char **envp, int *pipefd)
{
	int	file_descriptor;
	
	file_descriptor = ft_open(av[1], "infile");
	dup2(file_descriptor, 0);
	dup2(pipefd[0], pipefd[1]);
	close(pipefd[0]);
	execve();
}

/* Parent function */
void	ft_parent(char **av, char **envp, int*pipefd)
{
	int	file_descriptor;
	
	file_descriptor = ft_open(av[4], "outfile");
	dup2(file_descriptor, 1);
	dup2(pipefd[1], pipefd[0]);
	close(pipefd[1]); // we close the end
	ft_exec(av[3], 0);
}

/* Main */
int	main(int ac, char **av, char **envp)
{

	t_pipex	pipex;
	
	if (ac != 5)
		ft_exit(0);
	if (pipe(pipex.pipefd) == -1) // if pipe failed
		ft_exit(1);
	pipex.pid = fork();
	if (pipex.pid == -1) //if fork failed
		ft_exit(2);
	if (pipex.pid == 0) // child
		ft_child(av[2], envp, pipex.pipefd);
	if (pipex.pid > 0) // parent process
		ft_parent(av[3], envp, pipex.pipefd);
	waitpid(pipex.pid, NULL, 0);
	waitpid(pipex.pid, NULL, 0);
	return (0);
}
	// ---------------------------------

// 	if (pid == 0) // child process
// 	{
// 		close(pipefd[1]); // close unused write end
// 		dup2(pipefd[0], pipefd[1]);
// 		printf("Child : I am the child, my pid is %d\n", pid);
// 		close(pipefd[0]); //close read end
// 		execve("/bin/ls", &av[2], NULL);
// 	}
// 	else if (pid > 0) // parent process
// 	{
// 		close(pipefd[0]); // close unused read end
// 		printf("Parent : I am the parent, my pid is %d\n", pid);
// 		close(pipefd[1]); // close write end
// 		wait(NULL); // wait for child
// 	}
// 	return (0);
// }
/* 	int	pfd[2]; // create a pipe
	int	pid;

	if (pipe(pfd) == -1)
	{
		printf("Error: %s\n", strerror(errno));
		return (1);
	}
	pid = fork(); // creating a child
	if (pid == -1)
	{
		printf("Error: %s\n", strerror(errno));
		return (1);
	}
	printf("pid = %d\n", pid);
	
	return(0); */
//-------------------------------------------
/* 	(void)ac;
	(void)av;
	int	i;
	char **path_split;

	i = 0;
	while (envp[i])
	{

		if (ft_strncmp(envp[i], "PATH=", LEN_PATH) == 0)
			path_split = ft_split(envp[i] + LEN_PATH, ':');
		i++;
	}
	i = 0;
	while (path_split[i])
	{
		printf("%s\n", path_split[i]);
		i++;
	}
	return(0); */
//---------------------------------

	
	/* -----> DUP 2 EXAMPLE
	int fd;

	fd = open("test.txt", O_WRONLY | O_CREAT, 0644);
	// execve();
	dup2(fd, STDOUT_FILENO);
	close (fd);
	printf("KARL TEST\n"); */

//---------------------------------
/* -------> EXECVE EXAMPLE
	char *args[3];

	args[0] = "blablabla";
	args[1] = "-a";
	args[2] = NULL;
	execve("/bin/ls", args, NULL);
	printf("Testtest\n");
	return (0); */
	
/* 	pid_t pid;
 
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		printf("I am the child process.\n");
		sleep(2);
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("I am the parent process.\n");
		wait(NULL);
		printf("Child process terminated after a 2s delay.\n");
	}
 
	return (EXIT_SUCCESS); */

// int	pipefd[2]; //store the pipe's fds
// 				// pipefd[0] = read only and pipefd[1] = write only
	
// 	pid_t	pid;

// 	//creates a pipe
// 	if (pipe(pipefd) == -1) // if pipe creation failed
// 	{
// 		printf("error\n");
// 		exit(0);
// 	}

// 	pid = fork(); // parent receives PID of child, child receives PID 0
// 	if (pid == -1) //fork error
// 	{
// 		printf("error\n");
// 		exit(0);
// 	}
// 	if (pid == 0) // child process
// 	{
// 		close(pipefd[1]); // close unused write end
// 		dup2(pipefd[0], pipefd[1]);
// 		printf("Child : I am the child, my pid is %d\n", pid);
// 		close(pipefd[0]); //close read end
// 		execve("/bin/ls", &av[2], NULL);
// 	}
// 	else if (pid > 0) // parent process
// 	{
// 		close(pipefd[0]); // close unused read end
// 		printf("Parent : I am the parent, my pid is %d\n", pid);
// 		close(pipefd[1]); // close write end
// 		wait(NULL); // wait for child
// 	}
// 	return (0);
// }