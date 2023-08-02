/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:31:12 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/07/31 17:29:11 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangular(t_map *m)
{
	int	i;

	i = 0;
	while (i < m->height)
	{
		if (ft_strlen(m->map[i]) != m->width)
			error_exit("The map must be rectangular.\n");
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
					error_exit("The map must be surrounded by walls.\n");
				j++;
			}
		}
		else if (m->map[i][0] != '1' || m->map[i][m->width - 1] != '1')
				error_exit("The map must be surrounded by walls.\n");
		i++;
	}
}

void	check_CEP(t_map *m)
{
	if (m->e != 1)
		error_exit("The map must contain 1 exit.\n");
	else if (!m->c)
		error_exit("The map must contain at least 1 collectible.\n");
	else if (m->p != 1)
		error_exit("The map must contain 1 starting position.\n");
}

void	check_component(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->height)
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] == 'C')
				m->c++;
			else if (m->map[i][j] == 'E')
				m->e++;
			else if (m->map[i][j] == 'P')
			{
				m->p++;
				m->p_x = j;
				m->p_y = i;
			}
			else if (m->map[i][j] != '0' && m->map[i][j] != '1')
				error_exit("The map must be composed of only 5 characters(0, 1, C, E, P).\n");
			j++;
		}
		i++;
	}
}

void	check_valid_map(char *filename, t_map *m)
{
	map_info_init(filename, m);
	map_init(filename, m);
	check_rectangular(m);
	check_component(m);
	check_CEP(m);
	check_surrounded(m);
}