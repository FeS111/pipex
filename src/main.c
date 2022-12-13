/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:03:49 by fschmid           #+#    #+#             */
/*   Updated: 2022/12/13 16:08:03 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	fd;


	if (argc != 5)
		ft_exit("You need at exatly 4 arguments (./pipex file1 cmd1 cmd2 file2)", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_exit("", 0);
	pipex(argc, argv, env, fd);
	// system("leaks pipex");
	return (0);
}

void	pipex(int argc, char **argv, char **env, int fd)
{
	char	*output;
	int		out_fd;
	int 	i;

	i = 2;
	while (i < argc - 1)
	{
		
		i++;
	}
	close(fd);
	close(out_fd);
}

int	spawn_child(int in_fd, char *cmd, char **env)
{
	int		fds[2];
	pid_t	pid;
	char *const	args[4] = {SHELL_PATH, "-c", cmd, NULL};

	if (pipe(fds))
		ft_exit("pipe failed", 0);
	pid = fork();
	if (pid < 0)
		ft_exit("fork failed", 0);
	else if (pid == 0)
	{
		dup2(fds[1], STDOUT);
		dup2(in_fd, STDIN);
		close(fds[0]);
		close(fds[1]);
		close(in_fd);
	}
}