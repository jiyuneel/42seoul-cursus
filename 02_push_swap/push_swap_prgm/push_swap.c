/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 06:03:48 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/11 15:54:41 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack *a, t_stack *b, t_cmdset **head, float chunk);
void	b_to_a(t_stack *a, t_stack *b, t_cmdset **head);

// void check_leak() {
// 	system("leaks -quiet push_swap");
// }

int	main(int argc, char *argv[])
{
	t_stack		a;
	t_stack		b;
	t_cmdset	*head;
	float		chunk;

	// atexit(check_leak);
	stack_init(&a, &b, ++argv);
	if (argc == 1 || is_sorted(&a))
		return (0);
	head = NULL;
	if (a.len <= 5)
		sort_small_stack(&a, &b, &head);
	else
	{
		chunk = 0.000000053 * a.len * a.len + 0.03 * a.len + 14.5;
		a_to_b(&a, &b, &head, chunk);
		b_to_a(&a, &b, &head);
	}
	print_cmdset(head);
	free_list(&a);
	free_cmdset(head);
}

int	count_rotate(t_stack *a, int n, float chunk)
{
	int		cnt;
	t_list	*tmp;

	cnt = 0;
	tmp = a->top;
	while (tmp->idx > n + chunk)
	{
		cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}

void	a_to_b(t_stack *a, t_stack *b, t_cmdset **head, float chunk)
{
	int		top;
	int		n;
	int		cnt;

	n = 0;
	while (a->len)
	{
		top = a->top->idx;
		if (top <= n + chunk)
		{
			execute_and_add(a, b, head, PB);
			if (n++ < top)
				execute_and_add(a, b, head, RB);
		}
		else if (top > n + chunk)
		{
			cnt = count_rotate(a, n, chunk);
			if (cnt <= a->len / 2)
				while (cnt-- > 0)
					execute_and_add(a, b, head, RA);
			else
				while (cnt++ < a->len)
					execute_and_add(a, b, head, RRA);
		}
	}
}

void	b_to_a(t_stack *a, t_stack *b, t_cmdset **head)
{
	t_list	*tmp;
	int		big_idx;

	while (b->len)
	{
		tmp = b->top;
		big_idx = 0;
		while (tmp->idx != b->len - 1)
		{
			big_idx++;
			tmp = tmp->next;
		}
		if (big_idx <= b->len / 2)
			while (big_idx-- > 0)
				execute_and_add(a, b, head, RB);
		else
			while (big_idx++ < b->len)
				execute_and_add(a, b, head, RRB);
		execute_and_add(a, b, head, PA);
	}
}
