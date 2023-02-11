/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:20:23 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/11 16:47:59 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	stack_push(t_stack *stack, char **arr)
{
	long long	argval;
	t_list		*new;

	if (!arr || !*arr)
		error_exit(stack, NULL);
	while (*arr)
	{
		argval = to_integer(*arr);
		check_error(stack, *arr, argval);
		new = lstnew(argval);
		if (!new)
			error_exit(stack, NULL);
		lstadd_back(stack, new);
		arr++;
	}
}

void	stack_init(t_stack *a, t_stack *b, char **argv)
{
	char	**arr;

	if (!*argv)
		return ;
	a->len = 0;
	a->top = NULL;
	a->name = 'a';
	b->len = 0;
	b->top = NULL;
	b->name = 'b';
	while (*argv)
	{
		arr = split_space(*argv);
		stack_push(a, arr);
		free_arr(arr);
		argv++;
	}
}
