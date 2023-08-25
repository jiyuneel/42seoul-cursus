# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 16:41:00 by jiyunlee          #+#    #+#              #
#    Updated: 2023/08/25 18:59:09 by jiyunlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CC		= cc
CFLAGS	= -Wall -Wextra -Werror #-fsanitize=thread -g3

SRCS	= philo.c		philo_init.c	philo_start.c	philo_utils.c
OBJS	= ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	@echo "[ philo ]	Ready to run philo"

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -f ${OBJS}
	@echo "[ philo ]	Object files removed"

fclean:
	@rm -f ${OBJS} ${NAME}
	@echo "[ philo ]	Files removed"

re:	fclean all

.PHONY: all clean fclean re
