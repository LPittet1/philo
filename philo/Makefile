NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRCDIR = srcs/

SRCS =  $(SRCDIR)philo.c $(SRCDIR)parsing.c $(SRCDIR)utils.c $(SRCDIR)routine.c  $(SRCDIR)time.c $(SRCDIR)monitoring.c $(SRCDIR)init.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re