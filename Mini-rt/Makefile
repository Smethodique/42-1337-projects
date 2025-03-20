NAME = minirt
SOURCE = main.c config_parse/ft_split.c config_parse/get_next_line.c \
         config_parse/conf_parse.c config_parse/parse_extended.c config_parse/utils.c \
         config_parse/get_next_line_utils.c config_parse/parse_extended2.c \
         config_parse/helpers.c config_parse/ft_lst_func.c render/vector_op.c \
         render/mlx_lib.c render/setup_scene.c  render/Objects/sphere.c \
         render/render.c render/Objects/cylinder.c render/Objects/plane.c \
          hooks/hooks.c hooks/mouse.c hooks/handle_movement.c hooks/hooks2.c  render/render_helper.c \
          render/vector_op2.c

OBJ = $(SOURCE:.c=.o)
CC = cc 
CFLAGS =   -Wall -Wextra -Werror -O3 -ggdb3 -Iincludes 
LIBS =  -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
