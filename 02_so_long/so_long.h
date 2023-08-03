/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:27:20 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/03 03:08:38 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
/**/
# include <stdio.h>

typedef struct s_map
{
	char	**map;
	int		**visited;
	int		width;
	int		height;
	int		c;
	int		e;
	int		p;
	int		p_x;
	int		p_y;
}	t_map;

void	map_info_init(char *filename, t_map *m);
void	map_init(char *filename, t_map *m);
void	check_valid_file(int argc, char **argv);
void	check_valid_map(char *filename, t_map *m);
void	check_valid_path(t_map *m);
void	error_exit(char *str);
void	visited_init(t_map *m);

#endif