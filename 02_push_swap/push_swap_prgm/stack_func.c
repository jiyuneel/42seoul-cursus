/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:26:20 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/07 14:44:48 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (to->name == 'a')
		write(1, "pa\n", 3);
	else if (to->name == 'b')
		write(1, "pb\n", 3);
}

void	rotate(t_stack *stack)
{
	if (stack->len < 2)
		return ;
	stack->top = stack->top->next;
	if (stack->name == 'a')
		write(1, "ra\n", 3);
	else if (stack->name == 'b')
		write(1, "rb\n", 3);
}

void	rev_rotate(t_stack *stack)
{
	if (stack->len < 2)
		return ;
	stack->top = stack->top->prev;
	if (stack->name == 'a')
		write(1, "rra\n", 4);
	else if (stack->name == 'b')
		write(1, "rrb\n", 4);
}
