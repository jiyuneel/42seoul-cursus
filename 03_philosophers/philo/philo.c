/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:59:43 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/18 19:12:51 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (EXIT_FAILURE);
	memset(&data, 0, sizeof(t_data));
	philo_init(&data, argc, argv);
	printf("%d %d %d %d %d", data.number_of_philos, data.time_to_die, data.time_to_eat, data.time_to_sleep, data.number_of_times_philo_eat);
}
