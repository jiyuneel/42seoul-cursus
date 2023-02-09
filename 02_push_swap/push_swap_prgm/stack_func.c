/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:26:20 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/09 17:10:07 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_list	*top;
	int		tmp;

	if (stack->len < 2)
		return ;
	top = stack->top;
	tmp = top->val;
	top->val = top->next->val;
	top->next->val = tmp;
	if (stack->name == 'a')
		write(1, "sa\n", 3);
	else if (stack->name == 'b')
		write(1, "sb\n", 3);
}

void	push(t_stack *from, t_stack *to)
{
	t_list	*pop;

	if (from->len == 0)
		return ;
	pop = from->top;
	pop->prev->next = pop->next;
	from->top = from->top->next;
	from->top->prev = pop->prev;
	from->len--;
	if (from->len == 0)
		from->top = NULL;
	lstadd_back(to, pop);
	to->top = to->top->prev;
	if (to->name == 'a')
		write(1, "pa\n", 3);
	else if (to->name == 'b')
		write(1, "pb\n", 3);
}

void	rotate(t_stack *stack, int both)
{
	if (stack->len < 2)
		return ;
	stack->top = stack->top->next;
	if (!both)
	{
		if (stack->name == 'a')
			write(1, "ra\n", 3);
		else if (stack->name == 'b')
			write(1, "rb\n", 3);
	}
}

void	rev_rotate(t_stack *stack, int both)
{
	if (stack->len < 2)
		return ;
	stack->top = stack->top->prev;
	if (!both)
	{
		if (stack->name == 'a')
			write(1, "rra\n", 4);
		else if (stack->name == 'b')
			write(1, "rrb\n", 4);
	}
}

void	rotate_both(t_stack *a, t_stack *b, int reverse)
{
	if (reverse)
	{
		rev_rotate(a, 1);
		rev_rotate(b, 1);
		write(1, "rrr\n", 4);
	}
	else
	{
		rotate(a, 1);
		rotate(b, 1);
		write(1, "rr\n", 3);
	}
}
