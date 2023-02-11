/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:29:23 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/11 16:14:36 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}

void	rotate(t_stack *stack)
{
	if (stack->len < 2)
		return ;
	stack->top = stack->top->next;
}

void	rev_rotate(t_stack *stack)
{
	if (stack->len < 2)
		return ;
	stack->top = stack->top->prev;
}

void	rotate_both(t_stack *a, t_stack *b, int reverse)
{
	if (reverse)
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	else
	{
		rotate(a);
		rotate(b);
	}
}
