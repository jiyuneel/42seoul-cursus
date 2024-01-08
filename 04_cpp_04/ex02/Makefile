CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

NAME	= animal
SRCS	= main.cpp	Animal.cpp	Dog.cpp	Cat.cpp	\
		  WrongAnimal.cpp		WrongCat.cpp	\
		  Brain.cpp
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