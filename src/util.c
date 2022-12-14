/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:11:07 by fschmid           #+#    #+#             */
/*   Updated: 2022/12/14 12:02:58 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(char *error, int custom)
{
	if (custom == 0)
		perror(error);
	else
		ft_putendl_fd(error, 2);
	exit(1);
}

int	spawn_child(int in_fd, char *cmd, char **env)
{
	int			fds[2];
	pid_t		pid;
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
		execve(SHELL_PATH, args, env);
		return (-1);
	}
	close(fds[1]);
	close(in_fd);
	return (fds[0]);
}

void	write_output(int argc, char **argv, char *output)
{
	int	fd;

	fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 00777);
	if (fd < 0)
		ft_exit("Writing output failed: ", 0);
	write(fd, output, ft_strlen(output));
	close(fd);
}

char	*read_fd(int fd)
{
	char	*tmp;
	char	*content;
	char	*line;

	line = get_next_line(fd);
	content = ft_strdup("");
	while (line)
	{
		tmp = ft_strjoin(content, line);
		free(content);
		content = ft_strdup(tmp);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	return (content);
}
