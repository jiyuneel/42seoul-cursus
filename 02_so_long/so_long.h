/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:27:20 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/07/29 02:24:04 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
/**/
# include <stdio.h>

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		c;
	int		e;
	int		p;
}	t_map;

void	check_valid_file(int argc, char **argv);
void	check_valid_map(char *filename, t_map *m);

#endif