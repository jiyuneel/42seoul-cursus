/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:59:43 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/26 01:51:05 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_print(char *str)
{
	printf("%s", str);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (argc < 5 || argc > 6)
		return (error_print("Error\n"));
	if (data_init(&data, argc, argv))
		return (error_print("Error\nFail to initialize data.\n"));
	if (philo_init(&data, &philo))
		return (error_print("Error\nFail to initialize philosophers."));
	if (philo_start(&data, philo))
		return (error_print("Error\nFail to run the program."));
	return (EXIT_SUCCESS);
}
