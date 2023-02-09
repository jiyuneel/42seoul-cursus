/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:54:33 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/09 19:23:21 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_cmd(t_stack *a, t_stack *b, t_cmd cmd)
{
	if (cmd == SA)
		swap(a);
	else if (cmd == SB)
		swap(b);
	else if (cmd == PA)
		push(b, a);
	else if (cmd == PB)
		push(a, b);
	else if (cmd == RA)
		rotate(a, 0);
	else if (cmd == RB)
		rotate(b, 0);
	else if (cmd == RR)
		rotate_both(a, b, 0);
	else if (cmd == RRA)
		rev_rotate(a, 0);
	else if (cmd == RRB)
		rev_rotate(b, 0);
	else if (cmd == RRR)
		rotate_both(a, b, 1);
}

void	optimize_cmd(t_stack *a, t_stack *b, t_cmd prev, t_cmd curr)
{
	if (prev < 0 || curr == RB)
		return ;
	if (prev == RB && curr == RA)
		execute_cmd(a, b, RR);
	else if (prev == RB)
	{
		execute_cmd(a, b, RB);
		execute_cmd(a, b, curr);
	}
	else
		execute_cmd(a, b, curr);
}

void	sort_three(t_stack *a, t_stack *b)
{
	int	val1;
	int	val2;
	int	val3;

	val1 = a->top->val;
	val2 = a->top->next->val;
	val3 = a->top->prev->val;

	if (val2 < val1 && val1 < val3)
		execute_cmd(a, b, SA);
	else if (val2 < val3 && val3 < val1)
		execute_cmd(a, b, RA);
	else if (val3 < val1 && val1 < val2)
		execute_cmd(a, b, RRA);
	else if (val1 < val3 && val3 < val2)
	{
		execute_cmd(a, b, SA);
		execute_cmd(a, b, RA);
	}
	else if (val3 < val2 && val2 < val1)
	{
		execute_cmd(a, b, SA);
		execute_cmd(a, b, RRA);
	}
}

void	push_small(t_stack *a, t_stack *b, int idx)
{
	t_list	*tmp;
	int		push_idx;
	int		mid;

	tmp = a->top;
	push_idx = 0;
	while (tmp->idx != idx)
	{
		push_idx++;
		tmp = tmp->next;
	}
	mid = a->len / 2;
	if (push_idx > mid)
		while (push_idx++ < a->len)
			execute_cmd(a, b, RRA);
	else if (push_idx <= mid)
		while (push_idx-- > 0)
			execute_cmd(a, b, RA);
	execute_cmd(a, b, PB);
}

void	sort_small_stack(t_stack *a, t_stack *b)
{
	int	len;

	if (a->len == 2)
		execute_cmd(a, b, SA);
	else if (a->len == 3)
		sort_three(a, b);
	else
	{
		len = a->len;
		while (a->len != 3)
			push_small(a, b, len - a->len);
		sort_three(a, b);
		while (b->len != 0)
			execute_cmd(a, b, PA);
	}
}
