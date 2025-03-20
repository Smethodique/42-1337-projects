# Variables
executable = philo
SRC = main.c init.c parssing.c simulation.c utils.c take_fork.c monitor.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g3

all: $(executable)

$(executable): $(OBJ)
	$(CC) $(CFLAGS) -o $(executable) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(executable)

re: fclean all

.SECONDARY:
.PHONY: all clean fclean re


