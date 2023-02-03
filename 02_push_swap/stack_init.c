/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:25:31 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/03 14:28:33 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int val)
{
	t_list	*stack;

	stack = (t_list *)malloc(sizeof(t_list) * 1);
	if (!stack)
		return (NULL);
	stack->val = val;
	return (stack);
}

void	ft_lstadd_back(t_stack *stack, t_list *new)
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

void	stack_init(t_stack *a, t_stack *b, char **argv)
{
	int	i;

	a->len = 0;
	a->top = NULL;
	b->len = 0;
	b->top = NULL;
	i = 1;
	while (argv[i])
		ft_lstadd_back(a, ft_lstnew(atoi(argv[i++])));
}
