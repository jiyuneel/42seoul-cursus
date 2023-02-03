/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 06:05:38 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/03 16:41:03 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				val;
	int				idx;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	char			name;
	int				len;
	struct s_list	*top;
}	t_stack;

void	ft_lstadd_back(t_stack *stack, t_list *new);
void	stack_init(t_stack *a, t_stack *b, char **argv);
void	push(t_stack *from, t_stack *to);

#endif
