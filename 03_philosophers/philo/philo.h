/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:58:46 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/23 03:50:50 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

# define TRUE	1
# define FALSE	0

typedef struct s_data
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_eat;
	long long		start_time;
	pthread_mutex_t	print;
	pthread_mutex_t	dead;
	int				someone_dead; // dead flag
	int				finish;
	int				finish_eat;
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_philo
{
	int			id;
	int			left_fork;
	int			right_fork;
	int			eat_count;
	long long	last_eat_time;
	t_data		*data;
	pthread_t	thread_id;
}	t_philo;

int 		data_init(t_data *data, int argc, char **argv);
int			philo_init(t_data *data, t_philo **philo);
int			ft_atoi(const char *str);
int 		philo_start(t_data *data, t_philo *philo);
long long   get_time();

#endif
