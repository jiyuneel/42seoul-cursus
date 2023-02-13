/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:30:35 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/13 14:58:21 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (num < 0 && len >= 11 && num < INT_MIN)
		return (0);
	if (num >= 0 && len >= 10 && num > INT_MAX)
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

void	error_exit(t_stack *stack1, t_stack *stack2, t_cmdset *head)
{
	if (stack1)
		free_list(stack1);
	if (stack2)
		free_list(stack2);
	if (head)
		free_cmdset(head);
	write(2, "Error\n", 6);
	exit(1);
}

void	check_error(t_stack *stack, char *arg_str, long long arg_int)
{
	if (!check_digit(arg_str) || !check_range(arg_str, arg_int)
		|| !check_duplicate(stack, arg_int))
		error_exit(stack, NULL, NULL);
}
