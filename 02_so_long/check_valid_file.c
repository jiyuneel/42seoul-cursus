/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:28:53 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/07/31 17:29:03 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *str)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}

void	check_valid_file(int argc, char **argv)
{
	int		fd;
	char	*filename;
	size_t	len;

	if (argc != 2)
		error_exit("invalid argument\n");
	filename = argv[1];
	len = ft_strlen(filename);
	if (len <= 4 || ft_strncmp(filename + len - 4, ".ber", 4) || filename[len - 5] == '/')
		error_exit("invalid filename\n");
}