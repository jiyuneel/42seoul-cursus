/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:31:32 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/20 02:44:34 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig(pid_t pid, char *str);

void check(void) {
	system("leaks --quiet client");
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	atexit(check);
	if (argc != 3)
	{
		ft_putstr_fd("Error: wrong number of arguments\n", 1);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	send_sig(pid, argv[2]);
}

int	*to_binary(char c)
{
	int	*binary;
	int	i;

	binary = (int *)malloc(sizeof(int) * 8);
	if (!binary)
		exit(1);
	i = 0;
	while (i < 8)
		binary[i++] = 0;
	while (c)
	{
		binary[--i] = c % 2;
		c /= 2;
	}
	return (binary);
}

void	send_sig(pid_t pid, char *str)
{
	char	*tmp;
	size_t	len;
	int		*binary;
	int		i;

	str = ft_strjoin(str, "\n");
	tmp = str;
	if (!tmp)
		exit(1);
	len = ft_strlen(tmp);
	while (len--)
	{
		binary = to_binary(*tmp++);
		i = 0;
		while (i < 8)
		{
			if (binary[i] == 0)
				kill(pid, SIGUSR1);
			else if (binary[i] == 1)
				kill(pid, SIGUSR2);
			usleep(100);
			i++;
		}
		free(binary);
	}
	free(str);
}
