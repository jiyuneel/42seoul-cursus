/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:26:20 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/03 16:29:48 by jiyunlee         ###   ########.fr       */
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
	ft_lstadd_back(to, pop(from));
	to->top = to->top->prev;
	if (to->name == 'a')
		printf("pa\n");
	else if (to->name == 'b')
		printf("pb\n");
}
