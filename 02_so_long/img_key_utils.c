/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_key_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 01:44:40 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/08 16:55:42 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(t_map *m)
{
	int	w;
	int	h;
	int	i;

	m->img_0 = mlx_xpm_file_to_image(m->mlx, "./img/grass.xpm", &w, &h);
	m->img_1 = mlx_xpm_file_to_image(m->mlx, "./img/block.xpm", &w, &h);
	m->img_p[0][0] = mlx_xpm_file_to_image(m->mlx, "./img/mario.xpm", &w, &h);
	m->img_c = mlx_xpm_file_to_image(m->mlx, "./img/coin.xpm", &w, &h);
	m->img_e = mlx_xpm_file_to_image(m->mlx, "./img/flag.xpm", &w, &h);
	m->img_p[1][0] = mlx_xpm_file_to_image(m->mlx, "./img/left0.xpm", &w, &h);
	m->img_p[1][1] = mlx_xpm_file_to_image(m->mlx, "./img/left1.xpm", &w, &h);
	m->img_p[1][2] = mlx_xpm_file_to_image(m->mlx, "./img/left2.xpm", &w, &h);
	m->img_p[1][3] = mlx_xpm_file_to_image(m->mlx, "./img/left3.xpm", &w, &h);
	m->img_p[2][0] = mlx_xpm_file_to_image(m->mlx, "./img/right0.xpm", &w, &h);
	m->img_p[2][1] = mlx_xpm_file_to_image(m->mlx, "./img/right1.xpm", &w, &h);
	m->img_p[2][2] = mlx_xpm_file_to_image(m->mlx, "./img/right2.xpm", &w, &h);
	m->img_p[2][3] = mlx_xpm_file_to_image(m->mlx, "./img/right3.xpm", &w, &h);
	if (!m->img_0 || !m->img_1 || !m->img_e || !m->img_c || !m->img_p[0][0])
		exit(EXIT_FAILURE);
	i = 0;
	while (i < 4)
		if (!m->img_p[1][i] || !m->img_p[2][i++])
			exit(EXIT_FAILURE);
}

void	display_image(t_map *m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m->height)
	{
		j = -1;
		while (++j < m->width)
		{
			mlx_put_image_to_window(m->mlx, m->win, \
				m->img_0, j * 32, i * 32);
			if (m->map[i][j] == '1')
				mlx_put_image_to_window(m->mlx, m->win, \
					m->img_1, j * 32, i * 32);
			else if (m->map[i][j] == 'P')
				mlx_put_image_to_window(m->mlx, m->win, \
					m->img_p[0][0], j * 32, i * 32);
			else if (m->map[i][j] == 'E')
				mlx_put_image_to_window(m->mlx, m->win, \
					m->img_e, j * 32, i * 32);
			else if (m->map[i][j] == 'C')
				mlx_put_image_to_window(m->mlx, m->win, \
					m->img_c, j * 32, i * 32);
		}
	}
}

void	display_movement(t_map *m)
{
	char	*moves;
	char	*movements;

	m->movement++;
	ft_printf("Moves: %d\n", m->movement);
	moves = ft_itoa(m->movement - 1);
	if (!moves)
		exit(EXIT_FAILURE);
	movements = ft_strjoin("Movements: ", moves);
	if (!movements)
		exit(EXIT_FAILURE);
	mlx_string_put(m->mlx, m->win, 10, m->height * 32 + 15, BLACK, movements);
	free(moves);
	free(movements);
	moves = ft_itoa(m->movement);
	if (!moves)
		exit(EXIT_FAILURE);
	movements = ft_strjoin("Movements: ", moves);
	if (!movements)
		exit(EXIT_FAILURE);
	mlx_string_put(m->mlx, m->win, 10, m->height * 32 + 15, WHITE, movements);
	free(moves);
	free(movements);
}

void	move_player(t_map *m, int x, int y)
{
	if (m->map[y][x] == '1' || (m->map[y][x] == 'E' && m->c_cnt != m->c))
		return ;
	display_movement(m);
	mlx_put_image_to_window(m->mlx, m->win, m->img_0, m->p_x * 32, m->p_y * 32);
	if (m->map[y][x] == 'E' && m->c_cnt == m->c)
	{
		mlx_put_image_to_window(m->mlx, m->win, \
			m->img_p[m->player_lr][m->movement % 4], x * 32, y * 32);
		mlx_destroy_window(m->mlx, m->win);
		exit_game(CLEAR);
	}
	else
	{
		mlx_put_image_to_window(m->mlx, m->win, m->img_0, x * 32, y * 32);
		mlx_put_image_to_window(m->mlx, m->win, \
			m->img_p[m->player_lr][m->movement % 4], x * 32, y * 32);
		m->p_x = x;
		m->p_y = y;
		if (m->map[y][x] == 'C')
		{
			m->map[y][x] = '0';
			m->c_cnt++;
		}
	}
}

int	key_hook(int keycode, t_map *m)
{
	if (keycode == KEY_LEFT)
	{
		m->player_lr = LEFT;
		move_player(m, m->p_x - 1, m->p_y);
	}
	else if (keycode == KEY_RIGHT)
	{
		m->player_lr = RIGHT;
		move_player(m, m->p_x + 1, m->p_y);
	}
	else if (keycode == KEY_DOWN)
		move_player(m, m->p_x, m->p_y + 1);
	else if (keycode == KEY_UP)
		move_player(m, m->p_x, m->p_y - 1);
	else if (keycode == KEY_ESC)
		exit_game(OVER);
	return (0);
}
