/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:24:12 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/03/23 16:00:28 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_signal(int sig, siginfo_t *siginfo, void *p);

int	main(int argc, char *argv[])
{
	struct sigaction	sig;

	(void)argc, (void)argv;
	ft_putstr_fd("pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = receive_signal;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
}

void	receive_signal(int sig, siginfo_t *siginfo, void *p)
{
	static t_signal	signal;

	(void)p;
	if (sig == SIGUSR1)
		signal.chr <<= 1;
	else if (sig == SIGUSR2)
		signal.chr = (signal.chr << 1) | 1;
	signal.bit++;
	if (signal.bit == 8)
	{
		if (signal.chr == '\0')
			kill(siginfo->si_pid, SIGUSR1);
		else
			ft_putchar_fd(signal.chr, 1);
		signal.bit = 0;
		signal.chr = 0;
	}
}
