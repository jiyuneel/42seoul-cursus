# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 04:48:13 by jiyunlee          #+#    #+#              #
#    Updated: 2023/02/05 04:59:57 by jiyunlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= push_swap.c	list_func.c	check_error.c	stack_init.c	stack_func.c
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
