/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:29:54 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/07/28 17:13:15 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	check_valid_file(int argc, char **argv)
{
	int		fd;
	char	*filename;
	size_t	len;

	if (argc != 2)
	{
		ft_putstr_fd("Error\ninvalid argument\n", 1);
		exit(1);
	}
	filename = argv[1];
	len = ft_strlen(filename);
	if (len <= 4 || ft_strcmp(filename + len - 4, ".ber") || filename[len - 5] == '/')
	{
		ft_putstr_fd("Error\ninvalid filename\n", 1);
		exit(1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(1);
}

char **check_valid_map()
{
	return NULL;
}

int	main(int argc, char **argv)
{
	char	**map;

	check_valid_file(argc, argv);
	// map = check_valid_map();
}