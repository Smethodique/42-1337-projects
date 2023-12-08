SRC = ft_printf.c ft_putadress.c ft_putdec.c ft_putstr.c \
      ft_putuphex.c ft_calclen.c ft_putchar.c ft_puthex.c \
      ft_putunsdec.c

CC = gcc
OBJS = ${SRC:.c=.o}
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

${NAME}: $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all




