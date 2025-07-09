CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11
SRCS =  get_next_line_utils.c get_next_line.c keypress_handler.c \
		map_parser.c map_validator_utils.c map_validator.c mlx_utils.c \
			movements_utils.c movements.c path_validator.c render_map.c \
				so_long_utils.c so_long.c
OBJS = $(SRCS:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all fclean re clean