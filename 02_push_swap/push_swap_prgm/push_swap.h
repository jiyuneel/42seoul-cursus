/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 06:05:38 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/11 03:50:30 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

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

typedef enum e_cmd
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_cmd;

typedef struct s_cmdset
{
	enum e_cmd		cmd;
	struct s_cmdset	*prev;
	struct s_cmdset	*next;
}	t_cmdset;

void	sort_small_stack(t_stack *a, t_stack *b, t_cmdset **head);
char	**split_space(char const *s);
char	**free_arr(char **arr);
void	stack_init(t_stack *a, t_stack *b, char **argv);
int		is_sorted(t_stack *stack);
t_list	*lstnew(int val);
void	lstadd_back(t_stack *stack, t_list *new);
void	free_list(t_stack *stack);
void	check_error(t_stack *stack, char *arg_str, long long arg_int);
void	error_exit(t_stack *stack);
void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack);
void	rev_rotate(t_stack *stack);
void	rotate_both(t_stack *a, t_stack *b, int reverse);
void	execute_cmd(t_stack *a, t_stack *b, t_cmd cmd);
t_cmdset	*cmdnew(t_cmd cmd);
void	cmdadd_back(t_cmdset **head, t_cmdset *new);
void	print_cmd(t_cmd cmd);
void	execute_and_add(t_stack *a, t_stack *b, t_cmdset **head, t_cmd cmd);
void	free_cmdset(t_cmdset *head);

#endif
