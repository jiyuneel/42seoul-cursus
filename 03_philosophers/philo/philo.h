/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:58:46 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/08/27 13:45:23 by jiyunlee         ###   ########.fr       */
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

# define TRUE		1
# define FALSE		0
# define CONTINUE	1
# define BREAK		0

typedef enum e_state
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}	t_state;

typedef struct s_data
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_eat;
	long long		start_time;
	pthread_mutex_t	*forks;
	int				dead_flag;
	pthread_mutex_t	dead_mutex;
	int				full_count;
	pthread_mutex_t	full_mutex;
	int				stop_print;
	pthread_mutex_t	print_mutex;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread_id;
	t_data			*data;
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	long long		last_eat_time;
	pthread_mutex_t	time_mutex;
}	t_philo;

int			data_init(t_data *data, int argc, char **argv);
int			philo_init(t_data *data, t_philo **philo);
int			philo_start(t_data *data, t_philo *philo);
void		philo_print(t_data *data, t_philo *philo, t_state state);
int			check_finish(t_data *data);
long long	get_time(void);
void		delay_time(int time, t_data *data);
void		free_philo(t_data *data, t_philo *philo);

#endif
