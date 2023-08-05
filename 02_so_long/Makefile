NAME		= so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLIB		= -L${MLX_DIR} -lmlx -Imlx -framework OpenGL -framework AppKit

LIB_DIR		= ./libft
MLX_DIR		= ./mlx

SRCS		= so_long.c \
			  map_init.c \
			  check_valid_file.c \
			  check_valid_map.c \
			  check_valid_path.c \
			  play_game.c \
			  get_next_line/get_next_line.c
OBJS		= ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@make -C ${LIB_DIR} bonus
	@echo "[ libft ]	Ready to use libft.a"
	@make -C ${MLX_DIR}
	@echo "[ mlx ]		Ready to use MiniLibX"
	@$(CC) -o ${NAME} $(OBJS) -L${LIB_DIR} -lft $(MLIB)
	@install_name_tool -change libmlx.dylib mlx/libmlx.dylib ${NAME}
	@echo "[ so_long ]	Ready to use so_long"

%.o: %.c
	@${CC} ${CFLAGS} -Imlx -c $< -o $@

clean:
	@make -C ${LIB_DIR} clean
	@echo "[ libft ]	Object files removed"
	@make -C ${MLX_DIR} clean
	@echo "[ mlx ]		Object files removed"
	@rm -f ${OBJS}
	@echo "[ so_long ]	Object files removed"

fclean:
	@make -C ${LIB_DIR} fclean
	@echo "[ libft ]	Files removed"
	@make -C ${MLX_DIR} clean
	@echo "[ mlx ]		Files removed"
	@rm -f ${NAME} ${OBJS}
	@echo "[ so_long ]	Files removed"

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
