CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

NAME	= weapon
SRCS	= main.cpp	Weapon.cpp	HumanA.cpp	HumanB.cpp
OBJS	= ${SRCS:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

%.o: %.cpp
	@${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean:
	${RM} ${OBJS} ${NAME}

re:	fclean all

.PHONY: all clean fclean re