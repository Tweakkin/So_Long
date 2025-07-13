CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iminilibx-linux
MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11
M_SRCS =  ./mandatory/get_next_line_utils.c ./mandatory/get_next_line.c ./mandatory/keypress_handler.c ./mandatory/render_map.c \
		./mandatory/map_parser.c ./mandatory/map_validator_utils.c ./mandatory/map_validator.c ./mandatory/mlx_utils.c \
			./mandatory/movements_utils.c ./mandatory/movements.c ./mandatory/path_validator.c \
				./mandatory/so_long_utils.c ./mandatory/so_long.c
B_SRCS = ./bonus/get_next_line_utils_bonus.c ./bonus/get_next_line_bonus.c ./bonus/keypress_handler_bonus.c ./bonus/render_map_bonus.c \
		./bonus/map_parser_bonus.c ./bonus/map_validator_utils_bonus.c ./bonus/map_validator_bonus.c ./bonus/mlx_utils_bonus.c \
			./bonus/movements_utils_bonus.c ./bonus/movements_bonus.c ./bonus/path_validator_bonus.c \
				./bonus/so_long_utils_bonus.c ./bonus/so_long_bonus.c
M_OBJS = $(M_SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(M_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(M_OBJS) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(NAME) $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -o $(NAME) $(MLX_FLAGS)

clean :
	rm -rf $(M_OBJS) $(B_OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all fclean re clean