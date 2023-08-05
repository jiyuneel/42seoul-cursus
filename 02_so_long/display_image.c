/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 01:44:40 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/06 03:22:23 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_image(t_map *m)
{
    int     img_width;
	int     img_height;

    m->img_empty = mlx_xpm_file_to_image(m->mlx, "./img/grass.xpm", &img_width, &img_height);
    m->img_wall = mlx_xpm_file_to_image(m->mlx, "./img/block.xpm", &img_width, &img_height);
    m->img_player = mlx_xpm_file_to_image(m->mlx, "./img/mario/mario.xpm", &img_width, &img_height);
    m->img_exit = mlx_xpm_file_to_image(m->mlx, "./img/flag.xpm", &img_width, &img_height);
    m->img_collectible = mlx_xpm_file_to_image(m->mlx, "./img/coin.xpm", &img_width, &img_height);
    if (!m->img_empty || !m->img_wall || !m->img_player || !m->img_exit || !m->img_collectible)
        exit(1);
}

void    display_image(t_map *m)
{
    int i;
    int j;

    init_image(m);
    i = 0;
    while (i < m->height)
    {
        j = 0;
        while (j < m->width)
        {
            mlx_put_image_to_window(m->mlx, m->win, m->img_empty, j * 32, i * 32);
            if (m->map[i][j] == '1')
                mlx_put_image_to_window(m->mlx, m->win, m->img_wall, j * 32, i * 32);
            else if (m->map[i][j] == 'P')
                mlx_put_image_to_window(m->mlx, m->win, m->img_player, j * 32, i * 32);
            else if (m->map[i][j] == 'E')
                mlx_put_image_to_window(m->mlx, m->win, m->img_exit, j * 32, i * 32);
            else if (m->map[i][j] == 'C')
                mlx_put_image_to_window(m->mlx, m->win, m->img_collectible, j * 32, i * 32);
            j++;
        }
        i++;
    }
    // mlx_string_put(m->mlx, m->win, 20, 20, 255, "HELLO");
}
