/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:31:12 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/07/30 22:31:10 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (len <= 4 || ft_strncmp(filename + len - 4, ".ber", 4) || filename[len - 5] == '/')
	{
		ft_putstr_fd("Error\ninvalid filename\n", 1);
		exit(1);
	}
}

char	*read_file(char *filename, t_map *m)
{
	int		fd;
	char	buffer[1024];
	int		len;
	int		byte;
	char	*str;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(1);
	len = 0;
	while (1)
	{
		byte = read(fd, buffer, sizeof(buffer));
		if (byte <= 0)
			break ;
		len += byte;
	}
	if (byte < 0 || close(fd) < 0)
		exit(1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	fd = open(filename, O_RDONLY);
	if (!str || fd < 0 || read(fd, str, len) < 0 || close(fd) < 0)
		exit(1);
	str[len] = '\0';
	return str;
}

void	check_valid_map(char *filename, t_map *m)
{
	int	i;
	int	j;

	m->map = ft_split(read_file(filename, m), '\n');
	if (!m->map)
		exit(1);
	i = 0;
	while (m->map[i])
		i++;
	m->height = i;
	m->width = ft_strlen(m->map[0]);
}