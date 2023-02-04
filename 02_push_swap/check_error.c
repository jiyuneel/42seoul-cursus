/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:30:35 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/05 03:03:30 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(char *str)
{
	if (!*str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	check_range(long long num)
{
	if (num < -2147483648 || num > 2147483647)
		return (0);
	return (1);
}

int	check_duplicate(t_stack *stack, int val)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = stack->top;
	while (i < stack->len)
	{
		if (val == tmp->val)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void	error_exit(t_stack *stack)
{
	free_list(stack);
	write(2, "Error\n", 6);
	exit(1);
}

void	check_error(t_stack *stack, char *arg_str, long long arg_int)
{
	if (!check_digit(arg_str) || !check_range(arg_int) || !check_duplicate(stack, arg_int))
		error_exit(stack);
}
