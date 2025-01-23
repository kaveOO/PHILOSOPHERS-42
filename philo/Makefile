NAME		=	philo

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g $(INCLUDE)
INCLUDE		=	-I includes -I src/libscam/printf_fd
CLONE		=	git clone
RM			=	rm -f

SRC			=	src/core/philo.c		\
				src/core/inits.c		\
				src/handling/handling.c	\
				src/parsing/parsing.c	\
				src/libscam/functions.c	\
				src/utils/free.c		\
				src/utils/time.c		\
				src/core/actions.c		\
				src/core/meal.c		\
				src/libscam/printf_fd/ft_printf_fd_hex.c \
				src/libscam/printf_fd/ft_printf_fd_ptr.c \
				src/libscam/printf_fd/ft_printf_fd_utils.c \
				src/libscam/printf_fd/ft_printf_fd.c \


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
