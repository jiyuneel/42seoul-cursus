/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:31:32 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/03/23 15:39:21 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(pid_t pid, char *str);
void	receive_message(int sig);

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Error: wrong number of arguments\n", 1);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, receive_message);
	send_signal(pid, argv[2]);
}

void	send_character(pid_t pid, char c)
{
	int	bit;
	int	i;

	i = 8;
	while (i--)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else if (bit == 1)
			kill(pid, SIGUSR2);
		usleep(200);
	}
}

void	send_signal(pid_t pid, char *str)
{
	while (*str)
		send_character(pid, *str++);
	send_character(pid, '\n');
	send_character(pid, 127);
}

void	receive_message(int sig)
{
	if (sig == SIGUSR1)
		exit(0);
}
