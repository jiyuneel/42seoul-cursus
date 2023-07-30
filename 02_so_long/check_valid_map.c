/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:31:12 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/07/31 04:55:19 by jiyunlee         ###   ########.fr       */
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

void	free_arr(char **arr)
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
	size_t	len;

	m->map = (char **)malloc(sizeof(char *) * (m->height + 1));
	fd = open(filename, O_RDONLY);
	if (!m->map || fd < 0)
		exit(1);
	i = 0;
	while (i < m->height)
	{
		line = get_next_line(fd);
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			len--;
		m->map[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!m->map[i])
			free_arr(m->map);
		ft_strlcpy(m->map[i++], line, len + 1);
		free(line);
	}
	m->map[i] = NULL;
	if (close(fd) < 0)
		exit(1);
}

void	check_rectangular(t_map *m)
{
	int	i;

	i = 0;
	while (i < m->height)
	{
		if (ft_strlen(m->map[i]) != m->width)
		{
			ft_putstr_fd("Error\nThe map must be rectangular.\n", 1);
			exit(1);
			// free_arr(m->map);
		}
		i++;
	}
}

void	check_surrounded(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->height)
	{
		if (i == 0 || i == m->height - 1)
		{
			j = 0;
			while (m->map[i][j])
			{
				if (m->map[i][j] != '1')
				{
					ft_putstr_fd("Error\nThe map must be surrounded by walls.\n", 1);
					exit(1);
					// free_arr(m->map);
				}
				j++;
			}
		}
		else
		{
			if (m->map[i][0] != '1' || m->map[i][m->width - 1] != '1')
			{
				ft_putstr_fd("Error\nThe map must be surrounded by walls.\n", 1);
				exit(1);
				// free_arr(m->map);
			}
		}
		i++;
	}
}

void	check_valid_map(char *filename, t_map *m)
{
	int	i;
	int	j;

	get_map_info(filename, m);
	// printf("height:%d, width: %d\n", m->height, m->width);
	get_map(filename, m);
	// for (i = 0; m->map[i]; i++)
	// 	printf("%s\n", m->map[i]);
	check_rectangular(m);
	check_surrounded(m);
}