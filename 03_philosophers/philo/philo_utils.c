/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:50:50 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/26 06:25:23 by jiyunlee         ###   ########.fr       */
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

long long	get_time(void)
{
	struct timeval  time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	delay_time(int time, t_data *data)
{
	long long	start;

	start = get_time();
	while ((get_time() - start < time) && !check_finish(data))
		usleep(200);
}

void	philo_print(t_data *data, t_philo *philo, t_state state)
{
	pthread_mutex_lock(&data->print_mutex);
	if (data->stop_print)
	{
		pthread_mutex_unlock(&data->print_mutex);
		return ;
	}
	printf("%lld %d ", get_time() - data->start_time, philo->id);
	if (state == FORK)
		printf("has taken a fork\n");
	else if (state == EAT)
		printf("is eating\n");
	else if (state == SLEEP)
		printf("is sleeping\n");
	else if (state == THINK)
		printf("is thinking\n");
	else if (state == DIE)
	{
		data->stop_print = TRUE;
		printf("died\n");
	}
	pthread_mutex_unlock(&data->print_mutex);
}

void	free_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&philo[i].time_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->dead_mutex);
	pthread_mutex_destroy(&data->full_mutex);
	free(data->forks);
	free(philo);
}
