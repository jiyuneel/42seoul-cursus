/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:24:12 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/26 06:13:47 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init(t_data *data);
int	ft_atoi(const char *str);

int	data_init(t_data *data, int argc, char **argv)
{
	memset(data, 0, sizeof(t_data));
	data->number_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
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

	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philos);
	if (!data->forks)
		return (EXIT_FAILURE);
	i = 0;
	while (i < data->number_of_philos)
		if (pthread_mutex_init(&data->forks[i++], NULL))
			return (EXIT_FAILURE);
	if (pthread_mutex_init(&data->print_mutex, NULL)
		|| pthread_mutex_init(&data->dead_mutex, NULL)
		|| pthread_mutex_init(&data->full_mutex, NULL))
		return (EXIT_FAILURE);
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
		(*philo)[i].data = data;
		(*philo)[i].id = i + 1;
		(*philo)[i].left_fork = i;
		(*philo)[i].right_fork = (i + 1) % data->number_of_philos;
		(*philo)[i].eat_count = 0;
		if (pthread_mutex_init(&(*philo)[i].time_mutex, NULL))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_atoi(const char *str)
{
	long long	num;

	num = 0;
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (-1);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num);
}
