/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:03:49 by fschmid           #+#    #+#             */
/*   Updated: 2022/12/07 14:35:51 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	char	*input_file;
	char	*output_file;

	if (argc != 5)
		ft_exit("You need exactly 4 arguments (./pipex file1 cmd1 cmd2 file2)");
	input_file = read_file(argv[1]);
	ft_printf(input_file);
	free(input_file);
	free(output_file);
	system("leaks pipex");
	return (0);
}
