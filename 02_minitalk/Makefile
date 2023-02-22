# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 23:28:44 by jiyunlee          #+#    #+#              #
#    Updated: 2023/02/22 23:37:53 by jiyunlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS_C	= client.c		minitalk_utils.c
SRCS_S	= server.c		minitalk_utils.c

OBJS_C	= ${SRCS_C:.c=.o}
OBJS_S	= ${SRCS_S:.c=.o}

CLIENT	= client
SERVER	= server

all: ${CLIENT} ${SERVER}
bonus: 

${CLIENT}: ${OBJS_C}
	${CC} ${CFLAGS} ${OBJS_C} -o ${CLIENT}

${SERVER}: ${OBJS_S}
	${CC} ${CFLAGS} ${OBJS_S} -o ${SERVER}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS_C} ${OBJS_S}

fclean: clean
	rm -f ${CLIENT} ${SERVER}

re:	fclean all

.PHONY: all bonus clean fclean re
