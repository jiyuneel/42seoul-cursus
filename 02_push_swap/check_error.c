/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:30:35 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/04 18:46:33 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (c);
	return (0);
}

long long	ft_atoi(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (sign * num);
}

int	check_digit(char *str)
{
	if (!*str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
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

void	check_error(t_stack *stack, char *arg_str, long long *arg_int)
{
	*arg_int = ft_atoi(arg_str);
	if (!check_digit(arg_str) || !check_range(*arg_int))
	{
		// free_list();
		write(2, "Error\n", 6);
		exit(1);
	}
}
