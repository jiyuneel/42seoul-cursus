/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:53:17 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/08 16:43:30 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(int game)
{
	if (game == CLEAR)
		ft_printf("GAME CLEAR\n");
	else if (game == OVER)
		ft_printf("GAME OVER\n");
	exit(EXIT_SUCCESS);
}

void	play_game(t_map *m)
{
	m->mlx = mlx_init();
	if (!m->mlx)
		exit(EXIT_FAILURE);
	m->win = mlx_new_window(m->mlx, \
		m->width * 32, m->height * 32 + 25, "so_long");
	if (!m->win)
		exit(EXIT_FAILURE);
	m->player_lr = RIGHT;
	init_image(m);
	display_image(m);
	mlx_key_hook(m->win, key_hook, m);
	mlx_hook(m->win, KEY_EXIT, 0, exit_game, OVER);
	mlx_loop(m->mlx);
}
