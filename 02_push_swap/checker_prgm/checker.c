/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:11:11 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/07 14:31:40 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	char	*cmd;

	if (argc == 1)
		return (0);
	stack_init(&a, &b, ++argv);
	if (is_sorted(&a))
		return (0);
	while (1)
	{
		cmd = get_next_line(0);
		if (!cmd)
			break;
		// execute_cmd(&a, &b, cmd);
	}
	if (is_sorted(&a) && !b.len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(&a);
	free_list(&b);
}
