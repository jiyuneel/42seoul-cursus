/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:34:42 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/03 03:08:18 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_info_init(char *filename, t_map *m)
{
	int		fd;
	char	*line;
	size_t	len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
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
		exit(EXIT_FAILURE);
}

void	map_init(char *filename, t_map *m)
{
	int		fd;
	int		i;
	char	*line;
	size_t	len;

	m->map = (char **)malloc(sizeof(char *) * (m->height + 1));
	fd = open(filename, O_RDONLY);
	if (!m->map || fd < 0)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < m->height)
	{
		line = get_next_line(fd);
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			len--;
		m->map[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!m->map[i])
			exit(EXIT_FAILURE);
		ft_strlcpy(m->map[i++], line, len + 1);
		free(line);
	}
	m->map[i] = NULL;
	if (close(fd) < 0)
		exit(EXIT_FAILURE);
}

void	visited_init(t_map *m)
{
	int	i;
	int	j;

	m->visited = (int **)malloc(sizeof(int *) * m->height);
	if (!m->visited)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < m->height)
	{
		m->visited[i] = ft_calloc(m->width, sizeof(int));
		if (!m->visited[i])
			exit(EXIT_FAILURE);
		i++;
	}
}