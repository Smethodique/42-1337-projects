NAME = push_swap
SRCS = parsing.c parsingT.c linkedlis.c move.c moveT.c sortAlgo.c sortAlgoT.c sortAlgoTH.c sortAlgoF.c 
OBJS = $(SRCS:.c=.o)
LIBFT = 1337Libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
LDFLAGS = -L 1337Libft -lft 

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C 1337Libft

clean:
	rm -f $(OBJS)
	make -C 1337Libft clean

fclean: clean
	rm -f $(NAME)
	make -C 1337Libft fclean

re: fclean all

.PHONY: all clean fclean re