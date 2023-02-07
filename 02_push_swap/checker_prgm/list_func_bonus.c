/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:24:29 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/07 14:56:57 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_list	*lstnew(int val)
{
	t_list	*stack;

	stack = (t_list *)malloc(sizeof(t_list));
	if (!stack)
		return (NULL);
	stack->val = val;
	return (stack);
}

void	lstadd_back(t_stack *stack, t_list *new)
{
	if (!stack || !new)
		return ;
	if (!stack->top)
	{
		new->next = new;
		new->prev = new;
		stack->top = new;
	}
	else
	{
		new->prev = stack->top->prev;
		stack->top->prev->next = new;
		stack->top->prev = new;
		new->next = stack->top;
	}
	stack->len++;
}

void	free_list(t_stack *stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	while (stack->len--)
	{
		tmp = stack->top;
		stack->top = tmp->next;
		stack->top->prev = tmp->prev;
		tmp->prev->next = stack->top;
		free(tmp);
	}
}

int	is_sorted(t_stack *stack)
{
	t_list	*tmp;
	int		i;
	int		val;

	i = 0;
	tmp = stack->top;
	while (i < stack->len - 1)
	{
		val = tmp->val;
		if (val > tmp->next->val)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}
