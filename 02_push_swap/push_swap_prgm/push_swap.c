/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 06:03:48 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/09 19:24:57 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack *a, t_stack *b, t_cmd *prev, t_cmd *curr, float chunk);
void	b_to_a(t_stack *a, t_stack *b);

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_cmd	prev;
	t_cmd	curr;
	float	chunk;

	if (argc == 1)
		return (0);
	stack_init(&a, &b, ++argv);
	if (is_sorted(&a))
		return (0);
	if (a.len <= 5)
		sort_small_stack(&a, &b);
	else
	{
		prev = -1;
		chunk = 0.000000053 * a.len * a.len + 0.03 * a.len + 14.5;
		a_to_b(&a, &b, &prev, &curr, chunk);
		b_to_a(&a, &b);
	}
	free_list(&a);
}

void	a_to_b(t_stack *a, t_stack *b, t_cmd *prev, t_cmd *curr, float chunk)
{
	int	top;
	int	i;

	i = 0;
	while (a->len)
	{
		top = a->top->idx;
		if (top <= i + chunk)
		{
			*curr = PB;
			if (i < top)
			{
				optimize_cmd(a, b, prev, curr);
				*curr = RB;
			}
			i++;
		}
		else
			if (i < a->len / 2 && i >= 0)
				*curr = RRA;
			else
				*curr = RA;
		optimize_cmd(a, b, prev, curr);
	}
}

void	b_to_a(t_stack *a, t_stack *b)
{
	t_list	*tmp;
	int		big_idx;
	int		mid;

	while (b->len)
	{
		tmp = b->top;
		big_idx = 0;
		while (tmp->idx != b->len - 1)
		{
			big_idx++;
			tmp = tmp->next;
		}
		mid = b->len / 2;
		if (big_idx > mid)
			while (big_idx++ < b->len)
				execute_cmd(a, b, RRB);
		else if (big_idx <= mid)
			while (big_idx-- > 0)
				execute_cmd(a, b, RB);
		execute_cmd(a, b, PA);
	}
}
