/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:54:33 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/11 04:18:29 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_and_add(t_stack *a, t_stack *b, t_cmdset **head, t_cmd cmd)
{
	t_cmdset	*new;

	new = cmdnew(cmd);
	if (!new)
		error_exit(a, b, *head);
	execute_cmd(a, b, cmd);
	cmdadd_back(head, new);
}

void	sort_three(t_stack *a, t_stack *b, t_cmdset **head)
{
	int	val1;
	int	val2;
	int	val3;

	val1 = a->top->val;
	val2 = a->top->next->val;
	val3 = a->top->prev->val;

	if (val2 < val1 && val1 < val3)
		execute_and_add(a, b, head, SA);
	else if (val2 < val3 && val3 < val1)
		execute_and_add(a, b, head, RA);
	else if (val3 < val1 && val1 < val2)
		execute_and_add(a, b, head, RRA);
	else if (val1 < val3 && val3 < val2)
	{
		execute_and_add(a, b, head, SA);
		execute_and_add(a, b, head, RA);
	}
	else if (val3 < val2 && val2 < val1)
	{
		execute_and_add(a, b, head, SA);
		execute_and_add(a, b, head, RRA);
	}
}

void	push_small(t_stack *a, t_stack *b, t_cmdset **head, int idx)
{
	t_list	*tmp;
	int		push_idx;
	int		mid;

	tmp = a->top;
	push_idx = 0;
	while (tmp->idx != idx)
	{
		push_idx++;
		tmp = tmp->next;
	}
	mid = a->len / 2;
	if (push_idx > mid)
		while (push_idx++ < a->len)
			execute_and_add(a, b, head, RRA);
	else if (push_idx <= mid)
		while (push_idx-- > 0)
			execute_and_add(a, b, head, RA);
	execute_and_add(a, b, head, PB);
}

void	sort_small_stack(t_stack *a, t_stack *b, t_cmdset **head)
{
	int	len;

	if (a->len == 2)
		execute_and_add(a, b, head, SA);
	else if (a->len == 3)
		sort_three(a, b, head);
	else
	{
		len = a->len;
		while (a->len != 3)
			push_small(a, b, head, len - a->len);
		sort_three(a, b, head);
		while (b->len != 0)
			execute_and_add(a, b, head, PA);
	}
}

void	print_cmdset(t_cmdset *head)
{
	t_cmdset	*tmp;

	tmp = head;
	while (1)
	{
		if (tmp->cmd == RB && tmp->next->cmd == RA)
		{
			print_cmd(RR);
			tmp = tmp->next->next;
		}
		print_cmd(tmp->cmd);
		tmp = tmp->next;
		if (tmp == head)
			break ;
	}
}
