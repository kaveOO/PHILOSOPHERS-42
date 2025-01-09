NAME		=	philo

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g $(INCLUDE)
INCLUDE		=	-I includes
CLONE		=	git clone
RM			=	rm -f

SRC			=	src/core/philo.c		\
				src/core/inits.c		\
				src/handling/handling.c	\
				src/parsing/parsing.c	\
				src/libscam/functions.c	\
				src/utils/parsing.c		\

OBJ 		= $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re
