NAME		=	philo

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g $(INCLUDE)
INCLUDE		=	-I includes -I libft
CLONE		=	git clone
RM			=	rm -f

LIB			=	libft
LIBFT		=	$(LIB)/libft.a

SRC			=	src/core/philo.c		\
				src/core/inits.c		\
				src/handling/handling.c	\
				src/parsing/parsing.c	\

OBJ 		= $(SRC:.c=.o)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT): $(LIB)
		$(MAKE) -C $(LIB)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(LIB)

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(LIB)

re: fclean all

.PHONY:		all clean fclean re
