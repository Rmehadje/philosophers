NAME = philo
SOURCE = philosophers.c utils.c initializing.c error.c routine.c extra.c

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SOURCE:.c=.o)

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re