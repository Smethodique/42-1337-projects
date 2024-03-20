NAME = solong
SRCS = easy_path.c checkmaps.c 1337Libft/GNL/get_next_line.c 1337Libft/GNL/get_next_line_utils.c if_close.c easy_path2.c animation.c
OBJS = $(SRCS:.c=.o)
LIBFT = 1337Libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re