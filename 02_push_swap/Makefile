# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 04:48:13 by jiyunlee          #+#    #+#              #
#    Updated: 2023/02/06 15:33:37 by jiyunlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

DIR		= ./push_swap_prgm
SRCS	= \
${DIR}/push_swap.c		${DIR}/list_func.c		${DIR}/check_error.c \
${DIR}/stack_init.c		${DIR}/stack_func.c		${DIR}/split_space.c
OBJS	= ${SRCS:.c=.o}
NAME	= push_swap

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re
