# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 04:48:13 by jiyunlee          #+#    #+#              #
#    Updated: 2023/02/11 16:11:08 by jiyunlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

DIR		= ./push_swap_prgm
DIR_B	= ./checker_prgm
GNL		= ./get_next_line

SRCS	= \
${DIR}/push_swap.c		${DIR}/split_space.c	${DIR}/list_func.c	\
${DIR}/check_error.c	${DIR}/stack_init.c		${DIR}/stack_func.c \
${DIR}/cmd_func.c		${DIR}/optimize_cmd.c

SRCS_B	= \
${DIR_B}/checker_bonus.c		${DIR_B}/split_space_bonus.c \
${DIR_B}/list_func_bonus.c		${DIR_B}/check_error_bonus.c \
${DIR_B}/stack_init_bonus.c		${DIR_B}/stack_func_bonus.c  \
${DIR_B}/${GNL}/get_next_line.c	${DIR_B}/${GNL}/get_next_line_utils.c

OBJS	= ${SRCS:.c=.o}
OBJS_B	= ${SRCS_B:.c=.o}
NAME	= push_swap
BONUS	= checker

all: ${NAME}

bonus: ${BONUS}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${BONUS}: ${OBJS_B}
	${CC} ${CFLAGS} ${OBJS_B} -o ${BONUS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS} ${OBJS_B}

fclean: clean
	rm -f ${NAME} ${BONUS}

re:	fclean all

.PHONY: all bonus clean fclean re
