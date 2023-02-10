/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:53:06 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/10 22:31:43 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
