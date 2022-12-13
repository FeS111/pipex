/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:17:52 by fschmid           #+#    #+#             */
/*   Updated: 2022/12/13 16:53:38 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/src/libft.h"
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>

# define SHELL_PATH "/bin/bash"
# define STDIN 0
# define STDOUT 1

void	ft_exit(char *error, int custom);

char	*read_fd(int fd);

int	spawn_child(int in_fd, char *cmd, char **env);

void	write_output(int argc, char **argv, char *output);

void	pipex(int argc, char **argv, char **env, int fd);
#endif