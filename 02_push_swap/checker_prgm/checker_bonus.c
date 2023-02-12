/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:11:11 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/12 14:26:35 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	execute_cmd(t_stack *a, t_stack *b, char *cmd);
void	execute_cmd2(t_stack *a, t_stack *b, char *cmd);

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	char	*cmd;

	if (argc == 1)
		return (0);
	stack_init(&a, &b, ++argv);
	while (1)
	{
		cmd = get_next_line(0);
		if (!cmd)
			break ;
		execute_cmd(&a, &b, cmd);
		free(cmd);
	}
	if (is_sorted(&a) && !b.len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(&a);
	free_list(&b);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	execute_cmd(t_stack *a, t_stack *b, char *cmd)
{
	if (!ft_strcmp(cmd, "sa\n"))
		swap(a);
	else if (!ft_strcmp(cmd, "sb\n"))
		swap(b);
	else if (!ft_strcmp(cmd, "ss\n"))
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strcmp(cmd, "pa\n"))
		push(b, a);
	else if (!ft_strcmp(cmd, "pb\n"))
		push(a, b);
	else
		execute_cmd2(a, b, cmd);
}

void	execute_cmd2(t_stack *a, t_stack *b, char *cmd)
{
	if (!ft_strcmp(cmd, "ra\n"))
		rotate(a);
	else if (!ft_strcmp(cmd, "rb\n"))
		rotate(b);
	else if (!ft_strcmp(cmd, "rr\n"))
		rotate_both(a, b, 0);
	else if (!ft_strcmp(cmd, "rra\n"))
		rev_rotate(a);
	else if (!ft_strcmp(cmd, "rrb\n"))
		rev_rotate(b);
	else if (!ft_strcmp(cmd, "rrr\n"))
		rotate_both(a, b, 1);
	else
		error_exit(a, b);
}
