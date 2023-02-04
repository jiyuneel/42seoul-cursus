/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 06:03:48 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/05 03:58:39 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack *a, t_stack *b);
// void	b_to_a(t_stack *a, t_stack *b);

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	stack_init(&a, &b, argv + 1);
	a_to_b(&a, &b);
	// b_to_a(&a, &b);
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
		else if (top > i && top <= i + scale)
		{
			push(a, b);
			rotate(b);
			i++;
		}
		else if (top > i + scale)
			rotate(a);
	}
}
