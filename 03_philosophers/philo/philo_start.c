/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 00:24:38 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/23 03:55:47 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&(philo->data->print));
	// if (!philo->data->finish)
	printf("%lld %d %s\n", get_time() - philo->data->start_time, philo->id, str);
	pthread_mutex_unlock(&(philo->data->print));
}

void	delay_time(int time, t_data *data)
{
	long long	start;

	start = get_time();
	while (!data->finish)
	{
		if (get_time() - start >= time)
			break ;
		usleep(100);
	}
}

void	philo_eat(t_philo *philo)
{
	// long long	start;

	pthread_mutex_lock(&(philo->data->forks[philo->left_fork]));
	philo_print(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->data->forks[philo->right_fork]));
	philo_print(philo, "has taken another fork"); // another -> a
	philo_print(philo, "is eating");
	philo->last_eat_time = get_time();
	philo->eat_count += 1;
	// start = get_time();
	// while (get_time() - start < philo->data->time_to_eat)
	// 	usleep(100);
	delay_time(philo->data->time_to_eat, philo->data);
	pthread_mutex_unlock(&(philo->data->forks[philo->left_fork]));
	pthread_mutex_unlock(&(philo->data->forks[philo->right_fork]));
}

void	*philo_thread(void *ph)
{
	t_philo		*philo;
	long long	start;

	philo = (t_philo *)ph;
	if (philo->id % 2)
		usleep(500);
	philo->last_eat_time = get_time();
	while (!philo->data->finish)
	{
		philo_eat(philo);
		if (philo->data->number_of_times_eat == philo->eat_count)
		{
			philo->data->finish_eat += 1;
			break ;
		}
		philo_print(philo, "is sleeping");
		delay_time(philo->data->time_to_sleep, philo->data);
		// start = get_time();
		// while (get_time() - start < philo->data->time_to_eat)
		// 	usleep(100);	// 자거나 먹을 때도 죽었는지 계속 확인: check_dead: 내가 죽었는지, 남이 죽었는지
		philo_print(philo, "is thinking");
		usleep(200);
	}
	return (NULL);
}

int	check_philo_dead(t_data *data, t_philo *philo)
{
	int	i;

	while (!data->finish)
	{
		// number_of_times_eat 확인
		i = 0;
		while (i < data->number_of_philos)
		{
			if (get_time() - philo[i].last_eat_time >= data->time_to_die)
			{
				philo_print(&philo[i], "died");
				data->someone_dead = TRUE;
				break ;
			}
			i++;
		}
	}
}

int philo_start(t_data *data, t_philo *philo)
{
	int i;

	i = 0;
	while(i < data->number_of_philos)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, philo_thread, &philo[i]))
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
	return (EXIT_SUCCESS);
}
