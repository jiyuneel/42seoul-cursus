/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:50:50 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/22 19:15:02 by jiyunlee         ###   ########.fr       */
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

long long	get_time()
{
	struct timeval  time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
