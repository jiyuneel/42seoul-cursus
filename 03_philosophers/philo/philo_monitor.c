/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:29:58 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/25 18:11:20 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_finish(t_data *data)
{
	pthread_mutex_lock(&data->dead_mutex);
	if (data->dead_flag)
	{
		pthread_mutex_unlock(&data->dead_mutex);
		return (TRUE);
	}
	pthread_mutex_unlock(&data->dead_mutex);
	pthread_mutex_lock(&data->full_mutex);
	if (data->full_count == data->number_of_philos)
	{
		pthread_mutex_unlock(&data->full_mutex);
		return (TRUE);
	}
	pthread_mutex_unlock(&data->full_mutex);
	return (FALSE);
}

void	philo_monitor(t_data *data, t_philo *philo)
{
	int			i;

	usleep(500);
	while (!check_finish(data))
	{
		i = 0;
		while (i < data->number_of_philos)
		{
			pthread_mutex_lock(&philo[i].time_mutex);
			if (get_time() - philo[i].last_eat_time >= data->time_to_die)
			{
				pthread_mutex_unlock(&philo[i].time_mutex);
                philo_print(data, &philo[i], DIE);
				pthread_mutex_lock(&data->dead_mutex);
				data->dead_flag = TRUE;
				pthread_mutex_unlock(&data->dead_mutex);
				return ;
			}
			pthread_mutex_unlock(&philo[i].time_mutex);
			i++;
		}
		// usleep(200);
	}
}
