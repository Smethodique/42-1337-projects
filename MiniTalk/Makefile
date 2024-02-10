CC = gcc
CFLAGS = -Wall -Wextra -Werror

CLIENT_SRC = client.c
SERVER_SRC = server.c
UTILS_SRC = MinitalkUtils.c


CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
UTILS_OBJ = $(UTILS_SRC:.c=.o)

PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
PRINTF_INC = $(PRINTF_DIR)/ft_printf.h

all: client server

client: $(CLIENT_OBJ) $(UTILS_OBJ) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o client $(CLIENT_OBJ) $(UTILS_OBJ) $(PRINTF_LIB)

server: $(SERVER_OBJ) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o server $(SERVER_OBJ) $(PRINTF_LIB)


$(PRINTF_LIB):
	@make -C $(PRINTF_DIR)

%.o: %.c $(PRINTF_INC)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(PRINTF_DIR)

clean:
	@make -C $(PRINTF_DIR) clean
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(UTILS_OBJ)

fclean: clean
	@make -C $(PRINTF_DIR) fclean
	rm -f client server 

re: fclean all





