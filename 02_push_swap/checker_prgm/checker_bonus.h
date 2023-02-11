/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 03:18:40 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/11 17:09:15 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdlib.h>
# include <unistd.h>
# include "./get_next_line/get_next_line.h"

typedef struct s_list
{
	int				val;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	char			name;
	int				len;
	struct s_list	*top;
}	t_stack;

void	stack_init(t_stack *a, t_stack *b, char **argv);
char	**split_space(char const *s);
char	**free_arr(char **arr);
int		is_sorted(t_stack *stack);

t_list	*lstnew(int val);
void	lstadd_back(t_stack *stack, t_list *new);
void	free_list(t_stack *stack);

void	check_error(t_stack *stack, char *arg_str, long long arg_int);
void	error_exit(t_stack *stack1, t_stack *stack2);

void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack);
void	rev_rotate(t_stack *stack);
void	rotate_both(t_stack *a, t_stack *b, int reverse);

#endif
