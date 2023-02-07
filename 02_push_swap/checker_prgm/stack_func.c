/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:29:23 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/07 14:33:31 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*pop(t_stack *stack)
{
	t_list	*node;

	node = stack->top;
	node->prev->next = node->next;
	stack->top = stack->top->next;
	stack->top->prev = node->prev;
	stack->len--;
	if (stack->len == 0)
		stack->top = NULL;
	return (node);
}

void	push(t_stack *from, t_stack *to)
{
	if (from->len == 0)
		return ;
	lstadd_back(to, pop(from));
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
