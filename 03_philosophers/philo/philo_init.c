/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:24:12 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/21 21:56:01 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init(t_data *data);

int	philo_init(t_data *data, int argc, char **argv)
{
	data->number_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->number_of_philos <= 0 || data->time_to_die < 0
		||data->time_to_eat < 0 || data->time_to_sleep < 0)
		return (EXIT_FAILURE);
	if (argc == 6)
	{
		data->number_of_times_eat = ft_atoi(argv[5]);
		if (data->number_of_times_eat <= 0)
			return (EXIT_FAILURE);
	}
	mutex_init(data);
	return (EXIT_SUCCESS);
}

int	mutex_init(t_data *data)
{
	int	i;

	if (!pthread_mutex_init(&(data->print), NULL))
		return (EXIT_FAILURE);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philos);
	if (!data->forks)
		return (EXIT_FAILURE);
	while (i < data->number_of_philos)
	{
		if (!pthread_mutex_init(&(data->forks[i]), NULL))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
