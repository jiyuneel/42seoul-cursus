/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 02:10:59 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/03 03:08:52 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_path(t_map *m, int x, int y)
{
	if (m->map[y][x] == '1' || m->visited[y][x])
		return ;
	m->visited[y][x] = TRUE;
	if (m->map[y][x] == 'E')
		m->e_flag = TRUE;
	else if (m->map[y][x] == 'C')
		m->c_cnt++;
    valid_path(m, x + 1, y);
    valid_path(m, x - 1, y);
    valid_path(m, x, y + 1);
    valid_path(m, x, y - 1);
}

void	check_valid_path(t_map *m)
{
	visited_init(m);
	valid_path(m, m->p_x, m->p_y);
	if (m->e_flag == FALSE || m->c_cnt != m->c)
		error_exit("There is no valid path in the map.\n");
}