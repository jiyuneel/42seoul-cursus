/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:29:54 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/07/28 22:34:53 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	static t_map	m;

	check_valid_file(argc, argv);
	check_valid_map(argv[1], &m);
	// printf("c: %d, e: %d, p: %d\n", m.c, m.e, m.p);
}