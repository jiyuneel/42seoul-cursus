/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:59:43 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/23 19:44:48 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void leaks()
{
	system("leaks philo");
}

int	error_print(char *str)
{
	// malloc한 거 free해주기
	printf("%s\n", str);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	// atexit(leaks);
	if (argc < 5 || argc > 6)
		return (EXIT_FAILURE);
	memset(&data, 0, sizeof(t_data));
	if (data_init(&data, argc, argv))
		return (error_print("error data init"));
	if (philo_init(&data, &philo))
		return (error_print("error philo init"));
	if (philo_start(&data, philo))
		return (error_print("error philo start"));
	return (EXIT_SUCCESS);
}
