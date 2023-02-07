/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:54:33 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/07 20:55:16 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_cmd(t_stack *a, t_stack *b, t_cmd cmd)
{
	if (cmd == PA)
		push(b, a);
	else if (cmd == PB)
		push(a, b);
	else if (cmd == RA)
		rotate(a);
	else if (cmd == RB)
		rotate(b);
	else if (cmd == RR)
	{
		rotate(a);
		rotate(b);
	}
	else if (cmd == RRA)
		rev_rotate(a, 0);
	else if (cmd == RRB)
		rev_rotate(b, 0);
	else if (cmd == RRR)
		rotate_both(a, b, 1);
}

void	optimize_cmd(t_stack *a, t_stack *b, t_cmd prev, t_cmd curr)
{
	if (prev < 0)
		return ;
	// if (prev == RB && curr == RA)
	// 	execute_cmd(a, b, RRR);
	execute_cmd(a, b, curr);
}
