/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:24:12 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/21 20:03:38 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_signal(int sig);

int	main(int argc, char *argv[])
{
	ft_putstr_fd("pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, receive_signal);
	signal(SIGUSR2, receive_signal);
	while (1)
		pause();
}

void	receive_signal(int sig)
{
	static t_signal	signal;

	if (sig == SIGUSR1)
		signal.chr <<= 1;
	else if (sig == SIGUSR2)
	{
		signal.chr <<= 1;
		signal.chr |= 1;
	}
	signal.bit++;
	if (signal.bit == 8)
	{
		ft_putchar_fd(signal.chr, 1);
		signal.bit = 0;
		signal.chr = 0;
	}
}
