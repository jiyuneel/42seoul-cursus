/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 06:03:48 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/11 04:15:25 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack *a, t_stack *b, t_cmdset **head);
void	b_to_a(t_stack *a, t_stack *b, t_cmdset **head);

// void check_leak() {
// 	system("leaks -quiet push_swap");
// }

int	main(int argc, char *argv[])
{
	t_stack		a;
	t_stack		b;
	t_cmdset	*head;

	// atexit(check_leak);
	stack_init(&a, &b, ++argv);
	if (argc == 1 || is_sorted(&a))
		return (0);
	head = NULL;
	if (a.len <= 5)
		sort_small_stack(&a, &b, &head);
	else
	{
		a_to_b(&a, &b, &head);
		b_to_a(&a, &b, &head);
	}
	print_cmdset(head);
	free_list(&a);
	free_cmdset(head);
}

void	a_to_b(t_stack *a, t_stack *b, t_cmdset **head)
{
	int		top;
	int		n;
	float	chunk;
	int		r;
	t_list	*tmp;

	chunk = 0.000000053 * a->len * a->len + 0.03 * a->len + 14.5;
	n = 0;
	while (a->len)
	{
		r = 0;
		tmp = a->top;
		while (tmp->idx > n + chunk)
		{
			r++;
			tmp = tmp->next;
		}
		if (r > a->len / 2)
			while (r++ < a->len)
				execute_and_add(a, b, head, RRA);
		else
			while (r-- > 0)
				execute_and_add(a, b, head, RA);
		top = a->top->idx;
		if (top <= n + chunk)
		{
			execute_and_add(a, b, head, PB);
			if (n < top)
				execute_and_add(a, b, head, RB);
			n++;
		}
	}
}

void	b_to_a(t_stack *a, t_stack *b, t_cmdset **head)
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
				execute_and_add(a, b, head, RRB);
		else if (big_idx <= mid)
			while (big_idx-- > 0)
				execute_and_add(a, b, head, RB);
		execute_and_add(a, b, head, PA);
	}
}
