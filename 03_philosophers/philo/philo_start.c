/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 00:24:38 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/26 06:37:36 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_thread(void *ph);
int		philo_eat(t_data *data, t_philo *philo);
int		philo_sleep_think(t_data *data, t_philo *philo);
void	philo_monitor(t_data *data, t_philo *philo);

int	philo_start(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_mutex_lock(&philo[i].time_mutex);
		philo[i].last_eat_time = get_time();
		pthread_mutex_unlock(&philo[i].time_mutex);
		if (pthread_create(&philo[i].thread_id, NULL, philo_thread, &philo[i]))
			return (EXIT_FAILURE);
		i++;
	}
	philo_monitor(data, philo);
	i = 0;
	while (i < data->number_of_philos)
		pthread_join(philo[i++].thread_id, NULL);
	free_philo(data, philo);
	return (EXIT_SUCCESS);
}

void	*philo_thread(void *ph)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)ph;
	data = philo->data;
	if (philo->id % 2 == 0)
		usleep(500);
	while (!check_finish(data))
	{
		if (philo_eat(data, philo) == BREAK)
			break ;
		if (philo_sleep_think(data, philo) == BREAK)
			break ;
	}
	return (NULL);
}

int	philo_eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->forks[philo->left_fork]);
	philo_print(data, philo, FORK);
	if (data->number_of_philos == 1)
	{
		pthread_mutex_unlock(&data->forks[philo->left_fork]);
		return (BREAK);
	}
	pthread_mutex_lock(&data->forks[philo->right_fork]);
	philo_print(data, philo, FORK);
	philo_print(data, philo, EAT);
	pthread_mutex_lock(&philo->time_mutex);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->time_mutex);
	delay_time(data->time_to_eat, data);
	pthread_mutex_unlock(&data->forks[philo->left_fork]);
	pthread_mutex_unlock(&data->forks[philo->right_fork]);
	philo->eat_count += 1;
	if (philo->eat_count == data->number_of_times_eat)
	{
		pthread_mutex_lock(&data->full_mutex);
		data->full_count++;
		pthread_mutex_unlock(&data->full_mutex);
		return (BREAK);
	}
	return (CONTINUE);
}

int	philo_sleep_think(t_data *data, t_philo *philo)
{
	if (check_finish(data))
		return (BREAK);
	philo_print(data, philo, SLEEP);
	delay_time(data->time_to_sleep, data);
	if (check_finish(data))
		return (BREAK);
	philo_print(data, philo, THINK);
	usleep(200);
	return (CONTINUE);
}

void	philo_monitor(t_data *data, t_philo *philo)
{
	int	i;

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
	}
}
