/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:23:50 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/07 14:56:47 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_digit(char *str)
{
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

int	check_range(char *str, long long num)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	if (len > 11 || num < INT_MIN || num > INT_MAX)
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
	if (!check_digit(arg_str) || !check_range(arg_str, arg_int)
		|| !check_duplicate(stack, arg_int))
		error_exit(stack);
}
