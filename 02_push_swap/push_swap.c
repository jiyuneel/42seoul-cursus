/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 06:03:48 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/06 15:18:28 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack *a, t_stack *b);
void	b_to_a(t_stack *a, t_stack *b);

void check_leak() {
	system("leaks -quiet push_swap");
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	char	**arr;

	//atexit(check_leak);
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		arr = split_space(argv[1]);
		stack_init(&a, &b, arr);
		free_arr(arr);
	}
	else
		stack_init(&a, &b, ++argv);
	if (is_sorted(&a))
		return (0);
	a_to_b(&a, &b);
	b_to_a(&a, &b);
	// if (is_sorted(&a))
	// 	write(1, "OK\n", 3);
	// else
	// 	write(1, "KO\n", 3);
	free_list(&a);
}

void	a_to_b(t_stack *a, t_stack *b)
{
	float	scale;
	int		top;
	int		i;

	scale = 0.000000053 * a->len * a->len + 0.03 * a->len + 14.5;
	i = 0;
	while (a->len)
	{
		top = a->top->idx;
		if (top <= i)
		{
			push(a, b);
			i++;
		}
		else if (i < top && top <= i + scale)
		{
			push(a, b);
			rotate(b);
			i++;
		}
		else if (top > i + scale)
		{
			if (i < a->len / 2 && i >= 0)
				rev_rotate(a);
			else
				rotate(a);
		}
	}
}

int	get_big_idx(t_stack *stack)
{
	t_list	*tmp;
	int		i;

	tmp = stack->top;
	i = 0;
	while (1)
	{
		if (tmp->idx == stack->len - 1)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	b_to_a(t_stack *a, t_stack *b)
{
	int	big_idx;
	int	mid;

	while (b->len)
	{
		big_idx = get_big_idx(b);
		mid = b->len / 2;
		if (big_idx > mid)
		{
			while (big_idx < b->len)
			{
				rev_rotate(b);
				big_idx++;
			}
		}
		else if (big_idx <= mid)
		{
			while (big_idx > 0)
			{
				rotate(b);
				big_idx--;
			}
		}
		push(b, a);
	}
}
