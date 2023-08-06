# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/05 16:11:17 by jiyunlee          #+#    #+#              #
#    Updated: 2023/08/06 12:46:28 by jiyunlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLIB		= -L${MLX_DIR} -lmlx -Imlx -framework OpenGL -framework AppKit

LIB_DIR		= ./libftprintf
MLX_DIR		= ./mlx

SRCS		= so_long.c \
			  map_init.c \
			  check_valid_file.c \
			  check_valid_map.c \
			  check_valid_path.c \
			  display_image.c \
			  play_game.c \
			  key_utils.c \
			  get_next_line/get_next_line.c
OBJS		= ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@make -C ${LIB_DIR}
	@echo "[ libftprintf ]	Ready to use libftprintf.a"
	@make -C ${MLX_DIR}
	@echo "[ mlx ]		Ready to use MiniLibX"
	@$(CC) -o ${NAME} $(OBJS) -L${LIB_DIR} -lftprintf $(MLIB)
	@install_name_tool -change libmlx.dylib mlx/libmlx.dylib ${NAME}
	@echo "[ so_long ]	Ready to use so_long"

%.o: %.c
	@${CC} ${CFLAGS} -Imlx -c $< -o $@

clean:
	@make -C ${LIB_DIR} clean
	@echo "[ libftprintf ]	Object files removed"
	@make -C ${MLX_DIR} clean
	@echo "[ mlx ]		Object files removed"
	@rm -f ${OBJS}
	@echo "[ so_long ]	Object files removed"

fclean:
	@make -C ${LIB_DIR} fclean
	@echo "[ libftprintf ]	Files removed"
	@make -C ${MLX_DIR} clean
	@echo "[ mlx ]		Files removed"
	@rm -f ${NAME} ${OBJS}
	@echo "[ so_long ]	Files removed"

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
