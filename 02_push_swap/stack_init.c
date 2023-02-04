/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:25:31 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/04 21:29:41 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ('0' <= *str && *str <= '9'))
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (sign * num);
}

t_list	*ft_lstnew(int val)
{
	t_list	*stack;

	stack = (t_list *)malloc(sizeof(t_list));
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

void	set_idx(t_stack *stack)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		cnt;

	tmp1 = stack->top;
	while (1)
	{
		cnt = 0;
		tmp2 = stack->top;
		while (1)
		{
			if (tmp1->val > tmp2->val)
				cnt++;
			tmp2 = tmp2->next;
			if (tmp2 == stack->top)
				break ;
		}
		tmp1->idx = cnt;
		tmp1 = tmp1->next;
		if (tmp1 == stack->top)
			break ;
	}
}

void	stack_init(t_stack *a, t_stack *b, char **argv)
{
	long long	argval;
	t_list		*new;

	a->len = 0;
	a->top = NULL;
	a->name = 'a';
	b->len = 0;
	b->top = NULL;
	b->name = 'b';
	while (*argv)
	{
		argval = ft_atoi(*argv);
		check_error(a, *argv, argval);
		new = ft_lstnew(argval);
		if (!new)
		{
			free_list(a);
			write(2, "Error\n", 6);
			exit(1);
		}
		ft_lstadd_back(a, new);
		argv++;
	}
	set_idx(a);
}
