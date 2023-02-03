/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:26:20 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/03 16:26:47 by jiyunlee         ###   ########.fr       */
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
