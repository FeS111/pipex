/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:03:49 by fschmid           #+#    #+#             */
/*   Updated: 2022/12/14 12:01:25 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	fd;

	if (argc != 5)
		ft_exit("You need 4 arguments (./pipex file1 cmd1 cmd2 file2)", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_exit("", 0);
	pipex(argc, argv, env, fd);
	return (0);
}

void	pipex(int argc, char **argv, char **env, int fd)
{
	char	*output;
	int		out_fd;
	int		i;

	i = 2;
	while (i < argc - 1)
	{
		fd = spawn_child(fd, argv[i++], env);
		if (fd < 0)
			ft_exit("Spawing of child proccess failed", 0);
	}
	waitpid(0, NULL, 0);
	output = read_fd(fd);
	write_output(argc, argv, output);
	close(fd);
	close(out_fd);
	free(output);
}
