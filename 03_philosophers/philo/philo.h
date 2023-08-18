/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:58:46 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/18 19:41:25 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_eat;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_philo
{
}	t_philo;

int	philo_init(t_data *data, int argc, char **argv);
int	ft_atoi(const char *str);

#endif
