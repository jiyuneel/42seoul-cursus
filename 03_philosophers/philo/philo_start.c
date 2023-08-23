/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 00:24:38 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/23 19:40:48 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_finish(t_data *data)
{
	pthread_mutex_lock(&(data->dead));
	if (data->finish == TRUE)
	{
		pthread_mutex_unlock(&(data->dead));
		return (TRUE);
	}
	pthread_mutex_unlock(&(data->dead));
	return (FALSE);
}

void	philo_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&(philo->data->print));
	if (philo->data->no_print == TRUE)
	{
		pthread_mutex_unlock(&(philo->data->print));
		return ;
	}
	printf("%lld %d %s\n", get_time() - philo->data->start_time, philo->id, str);
	pthread_mutex_unlock(&(philo->data->print));
}

void	philo_dead_print(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->print));
	if (philo->data->no_print == TRUE)
	{
		pthread_mutex_unlock(&(philo->data->print));
		return ;
	}
	philo->data->no_print = TRUE;
	printf("%lld %d %s\n", get_time() - philo->data->start_time, philo->id, "died");
	pthread_mutex_unlock(&(philo->data->print));
}


void	delay_time(int time, t_data *data)
{
	long long	start;

	(void)data;
	start = get_time();
	while (get_time() - start < time)
	{
		if (check_finish(data))
			break ;
		usleep(200);
	}
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
	philo_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
	philo_print(philo, "has taken a fork"); // another -> a
	philo_print(philo, "is eating");
	pthread_mutex_lock(&philo->time);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->time);
	delay_time(philo->data->time_to_eat, philo->data);
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
	philo->eat_count += 1;
}

void	*philo_thread(void *ph)
{
	t_philo		*philo;

	philo = (t_philo *)ph;
	pthread_mutex_lock(&philo->time);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->time);

	if (philo->id % 2 == 0)
		usleep(800);
	while (!check_finish(philo->data))
	{
		philo_eat(philo);
		if (philo->data->number_of_times_eat == philo->eat_count)
		{
			pthread_mutex_lock(&philo->data->full);
			philo->data->finish_eat++;
			pthread_mutex_unlock(&philo->data->full);
			break ;
		}
		if (check_finish(philo->data))
			break ;
		philo_print(philo, "is sleeping");
		delay_time(philo->data->time_to_sleep, philo->data);
		if (check_finish(philo->data))
			break ;
		philo_print(philo, "is thinking");
		usleep(200);
	}
	return (NULL);
}

void	check_philo_dead(t_data *data, t_philo *philo)
{
	int	i;
	long long	time;

	usleep(1000);  
	while (!check_finish(data))
	{
		i = 0;
		while (i < data->number_of_philos)
		{
			pthread_mutex_lock(&philo[i].time);
			time = philo[i].last_eat_time;
			pthread_mutex_unlock(&philo[i].time);
			if (get_time() - time >= data->time_to_die)
			{
				philo_dead_print(&philo[i]);
				pthread_mutex_lock(&data->dead);
				data->finish = TRUE;
				pthread_mutex_unlock(&data->dead);
				return ;
			}
			i++;
		}
		pthread_mutex_lock(&data->full);
		if (data->finish_eat == data->number_of_philos)
		{
			pthread_mutex_unlock(&data->full);
			break ;
		}
		pthread_mutex_unlock(&data->full);
		usleep(300);
	}
}

int	philo_start(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		if (pthread_create(&philo[i].thread_id, NULL, philo_thread, &philo[i]))
			return (EXIT_FAILURE);
		i++;
	}
	check_philo_dead(data, philo);
	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->dead);
	pthread_mutex_destroy(&data->full);
	for (int j = 0; j < data->number_of_philos; j++)
	{
		pthread_mutex_destroy(&data->forks[j]);
		pthread_mutex_destroy(&philo[j].time);
	}
	return (EXIT_SUCCESS);
}
