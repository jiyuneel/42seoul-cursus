/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 06:03:48 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/10 19:34:11 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack *a, t_stack *b, t_cmd *prev, t_cmd *curr);
void	b_to_a(t_stack *a, t_stack *b);

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_cmd	prev;
	t_cmd	curr;

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
		a_to_b(&a, &b, &prev, &curr);
		b_to_a(&a, &b);
	}
	free_list(&a);
}

// void	a_to_b(t_stack *a, t_stack *b, t_cmd *prev, t_cmd *curr)
// {
// 	int		top;
// 	int		n;
// 	float	chunk;
// 	int		r;
// 	t_list	*tmp;

// 	chunk = 0.000000053 * a->len * a->len + 0.03 * a->len + 14.5;
// 	n = 0;
// 	while (a->len)
// 	{
// 		top = a->top->idx;
// 		//rotate_a(a, b, n, chunk, prev, curr);
// 		r = 0;
// 		tmp = a->top;
// 		while (tmp->idx > n + chunk)
// 		{
// 			r++;
// 			tmp = tmp->next;
// 		}
// 		if (r > a->len / 2)
// 		{
// 			*curr = RRA;
// 			while (r++ < a->len)
// 				//execute_cmd(a, b, RRA);
// 				optimize_cmd(a, b, prev, curr);
// 		}
// 		else
// 		{
// 			*curr = RA;
// 			while (r-- > 0)
// 				//execute_cmd(a, b, RA);
// 				optimize_cmd(a, b, prev, curr);
// 		}
// 		if (top <= n + chunk)
// 		{
// 			*curr = PB;
// 			if (n < top)
// 			{
// 				optimize_cmd(a, b, prev, curr);
// 				*curr = RB;
// 			}
// 			n++;
// 			optimize_cmd(a, b, prev, curr);
// 		}
// 	}
// }

int	rotate_num(t_stack *a, int n, float chunk)
{
	int		times;
	t_list	*tmp;

	times = 0;
	tmp = a->top;
	while (tmp->idx > n + chunk)
	{
		times++;
		tmp = tmp->next;
	}
	return (times);
}

void	a_to_b(t_stack *a, t_stack *b, t_cmd *prev, t_cmd *curr)
{
	int		n;
	float	chunk;
	int		times;

	chunk = 0.000000053 * a->len * a->len + 0.03 * a->len + 14.5;
	n = 0;
	while (a->len)
	{
		times = rotate_num(a, n, chunk);
		if (times > a->len / 2)
		{
			*curr = RRA;
			while (times++ < a->len)
				optimize_cmd(a, b, prev, curr);
		}
		else
		{
			*curr = RA;
			while (times-- > 0)
				optimize_cmd(a, b, prev, curr);
		}
		*curr = PB;
		if (n++ < a->top->idx)
		{
			optimize_cmd(a, b, prev, curr);
			*curr = RB;
		}
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
