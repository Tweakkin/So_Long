#include "so_long.h"

void	print_moves(int nbr)
{
	ft_putnbr(nbr);
	write(1, "\n", 1);
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