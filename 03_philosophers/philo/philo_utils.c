/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:50:50 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/21 17:21:48 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (c);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	num;

	num = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (-1);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num);
}

// int	ft_atoi(const char *str)
// {
// 	long long	num;
// 	int			sign;

// 	num = 0;
// 	sign = 1;
// 	while ((9 <= *str && *str <= 13) || *str == ' ')
// 		str++;
// 	if (*str == '+')
// 		str++;
// 	else if (*str == '-')
// 	{
// 		sign = -1;
// 		str++;
// 	}
// 	while (*str && ft_isdigit(*str))
// 	{
// 		num = num * 10 + (*str - '0');
// 		str++;
// 	}
// 	return (sign * num);
// }
