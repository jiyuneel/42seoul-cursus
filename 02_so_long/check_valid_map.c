/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:31:12 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/07/30 23:29:33 by jiyunlee         ###   ########.fr       */
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

void	get_map_info(char *filename, t_map *m)
{
	int		fd;
	char	*line;
	size_t	len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!m->width)
		{
			len = ft_strlen(line);
			if (line[len - 1] == '\n')
				m->width = len - 1;
			else
				m->width = len;
		}
		m->height++;
		free(line);
	}
	if (close(fd) < 0)
		exit(1);
}

char	**free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	exit(1);
}

void	get_map(char *filename, t_map *m)
{
	int		fd;
	int		i;
	char	*line;

	m->map = (char **)malloc(sizeof(char *) * (m->height + 1));
	if (!m->map)
		exit(1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(1);
	i = 0;
	while (i < m->height)
	{
		line = get_next_line(fd);
		m->map[i] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!m->map[i])
			free_arr(m->map);
		ft_strlcpy(m->map[i], line, ft_strlen(line) + 1);
		i++;
		free(line);
	}
	m->map[i] = NULL;
	if (close(fd) < 0)
		exit(1);
}

void	check_valid_map(char *filename, t_map *m)
{
	int	i;
	int	j;

	get_map_info(filename, m);
	// printf("height:%d, width: %d\n", m->height, m->width);
	get_map(filename, m);
	// for (i = 0; m->map[i]; i++)
	// 	printf("%s", m->map[i]);
}