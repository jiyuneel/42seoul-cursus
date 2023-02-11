/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:53:06 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/11 15:20:27 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_cmd(t_stack *a, t_stack *b, t_cmd cmd)
{
	if (cmd == SA)
		swap(a);
	else if (cmd == SB)
		swap(b);
	else if (cmd == PA)
		push(b, a);
	else if (cmd == PB)
		push(a, b);
	else if (cmd == RA)
		rotate(a);
	else if (cmd == RB)
		rotate(b);
	else if (cmd == RR)
		rotate_both(a, b, 0);
	else if (cmd == RRA)
		rev_rotate(a);
	else if (cmd == RRB)
		rev_rotate(b);
	else if (cmd == RRR)
		rotate_both(a, b, 1);
}

void	print_cmd(t_cmd cmd)
{
	if (cmd == SA)
		write(1, "sa\n", 3);
	else if (cmd == SB)
		write(1, "sb\n", 3);
	else if (cmd == PA)
		write(1, "pa\n", 3);
	else if (cmd == PB)
		write(1, "pb\n", 3);
	else if (cmd == RA)
		write(1, "ra\n", 3);
	else if (cmd == RB)
		write(1, "rb\n", 3);
	else if (cmd == RR)
		write(1, "rr\n", 3);
	else if (cmd == RRA)
		write(1, "rra\n", 4);
	else if (cmd == RRB)
		write(1, "rrb\n", 4);
	else if (cmd == RRR)
		write(1, "rrr\n", 4);
}

t_cmdset	*cmdnew(t_cmd cmd)
{
	t_cmdset	*node;

	node = (t_cmdset *)malloc(sizeof(t_cmdset));
	if (!node)
		return (NULL);
	node->cmd = cmd;
	return (node);
}

void	cmdadd_back(t_cmdset **head, t_cmdset *new)
{
	if (!*head)
	{
		new->next = new;
		new->prev = new;
		*head = new;
	}
	else
	{
		new->prev =(*head)->prev;
		(*head)->prev->next = new;
		(*head)->prev = new;
		new->next = *head;
	}
}

void	free_cmdset(t_cmdset *head)
{
	t_cmdset	*tmp;

	while (1)
	{
		tmp = head;
		head = tmp->next;
		head->prev = tmp->prev;
		tmp->prev->next = head;
		free(tmp);
		if (tmp->next == tmp)
			break ;
	}
}
