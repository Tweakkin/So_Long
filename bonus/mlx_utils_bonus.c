#include "so_long.h"

void	print_moves(t_game *game)
{
	char *moves_str;

    moves_str = ft_itoa(game->moves_counter);
	mlx_set_font(game->mlx, game->mlx_window, "rk24");
	//mlx_do_sync(game->mlx);
	//mlx_string_put(game->mlx, game->mlx_window, 100, 100, 0x000000, "               ");
    mlx_string_put(game->mlx, game->mlx_window, 100, 100, 0x000000, moves_str);
	mlx_do_sync(game->mlx);
	game->last_move = game->moves_counter;
    free(moves_str);
}

void	ft_putnbr(int n)
{
	long	num;
	char	c;

	num = (long)n;
	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num > 9)
		ft_putnbr(num / 10);
	c = (num % 10) + '0';
	ft_putchar(c);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}