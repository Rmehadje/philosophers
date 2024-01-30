NAME = philosophers
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SOURCE = philosophers.c utils.c initializing.c error.c routine.c

OBJ = $(SOURCE.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SOURCE) -o $(NAME)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re