/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:11:07 by fschmid           #+#    #+#             */
/*   Updated: 2022/12/07 14:27:01 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(char *error)
{
	ft_putendl_fd(error, 2);
	exit(1);
}

char	*read_file(char *file)
{
	char	*tmp;
	char	*content;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (NULL);
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
	close(fd);
	return (content);
}
