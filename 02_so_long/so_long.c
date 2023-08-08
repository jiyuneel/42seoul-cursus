/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:29:54 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/07 21:16:24 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	static t_map	m;

	check_valid_file(argc, argv);
	check_valid_map(argv[1], &m);
	check_valid_path(&m);
	play_game(&m);
}
