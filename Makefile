NAME		= philo

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

SRCS		= philo.c \
			parsing.c \
			first_inicial.c \
			threads.c \
			utils_1.c

OBJS		= $(SRCS:.c=.o)

RM			= rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) -I. $(CFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all