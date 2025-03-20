NAME = so_long
SRCS = easy_path.c checkmaps.c 1337Libft/GNL/get_next_line.c 1337Libft/GNL/get_next_line_utils.c if_close.c easy_path2.c coins_exit.c animation.c draw.c move.c
OBJS = $(SRCS:.c=.o)
LIBFT = 1337Libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
LDFLAGS = -L1337Libft -lft -lmlx -lX11 -lXext -lm 

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
