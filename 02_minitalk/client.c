/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:31:32 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/21 20:08:43 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(pid_t pid, char *str);

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Error: wrong number of arguments\n", 1);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	send_signal(pid, argv[2]);
}

void	send_signal(pid_t pid, char *str)
{
	char	*tmp;
	int		bit;
	int		i;

	str = ft_strjoin(str, "\n");
	if (!str)
		exit(1);
	tmp = str;
	while (*tmp)
	{
		i = 8;
		while (i--)
		{
			bit = (*tmp >> i) & 1;
			if (bit == 0)
				kill(pid, SIGUSR1);
			else if (bit == 1)
				kill(pid, SIGUSR2);
			usleep(100);
		}
		tmp++;
	}
	free(str);
}
