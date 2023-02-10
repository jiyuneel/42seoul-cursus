/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:25:31 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/10 19:35:07 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	to_integer(const char *str)
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

void	stack_push(t_stack *stack, char **arr)
{
	long long	argval;
	t_list		*new;

	if (!arr || !*arr)
		error_exit(stack);
	while (*arr)
	{
		argval = to_integer(*arr);
		check_error(stack, *arr, argval);
		new = lstnew(argval);
		if (!new)
			error_exit(stack);
		lstadd_back(stack, new);
		arr++;
	}
}

void	stack_init(t_stack *a, t_stack *b, char **argv)
{
	char	**arr;

	a->len = 0;
	a->top = NULL;
	a->name = 'a';
	b->len = 0;
	b->top = NULL;
	b->name = 'b';
	if (!argv)
		error_exit(a);
	while (*argv)
	{
		arr = split_space(*argv);
		stack_push(a, arr);
		free_arr(arr);
		argv++;
	}
	set_idx(a);
}
