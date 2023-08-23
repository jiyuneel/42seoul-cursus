/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:24:12 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/23 19:44:10 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init(t_data *data);

int	data_init(t_data *data, int argc, char **argv)
{
	data->number_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->number_of_times_eat = -1;
	// data->someone_dead = FALSE;
	data->finish = FALSE;
	// data->finish_eat = FALSE;
	if (data->number_of_philos <= 0 || data->time_to_die < 0
		|| data->time_to_eat < 0 || data->time_to_sleep < 0)
		return (EXIT_FAILURE);
	if (argc == 6)
	{
		data->number_of_times_eat = ft_atoi(argv[5]);
		if (data->number_of_times_eat <= 0)
			return (EXIT_FAILURE);
	}
	if (mutex_init(data))
		return (EXIT_FAILURE);
	data->start_time = get_time();
	return (EXIT_SUCCESS);
}

int	mutex_init(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&data->print, NULL) \
	|| pthread_mutex_init(&data->dead, NULL) \
	|| pthread_mutex_init(&data->full, NULL))
		return (EXIT_FAILURE);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philos);
	if (!data->forks)
		return (EXIT_FAILURE);
	i = 0;
	while (i < data->number_of_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	philo_init(t_data *data, t_philo **philo)
{
	int	i;

	*philo = malloc(sizeof(t_philo) * data->number_of_philos);
	if (!*philo)
		return (EXIT_FAILURE);
	i = 0;
	while (i < data->number_of_philos)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].left_fork = i;
		(*philo)[i].right_fork = (i + 1) % data->number_of_philos;
		if (pthread_mutex_init(&(*philo)[i].time, NULL))
			return (EXIT_FAILURE);
		(*philo)[i].eat_count = 0;
		(*philo)[i].data = data;
		i++;
	}
	return (EXIT_SUCCESS);
}
