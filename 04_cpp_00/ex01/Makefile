NAME	= phonebook

CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -f

SRCS	= PhoneBook.cpp		Contact.cpp		main.cpp
OBJS	= ${SRCS:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o: %.cpp
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean:
	${RM} ${OBJS} ${NAME}

re:	fclean all

.PHONY: all clean fclean re