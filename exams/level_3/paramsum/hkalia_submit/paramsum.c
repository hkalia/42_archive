#include <unistd.h>

void	ft_putchar(char src)
{
	write(1, &src, 1);
}

void	ft_putnbr(int src)
{
	long	src_cpy;
	
	src_cpy = src;
	if (src_cpy > 9)
	{
		ft_putnbr(src / 10);
		ft_putnbr(src % 10);
	}
	else
		ft_putchar(src + '0');
}

int		main(int argc, char **argv)
{
	argv = 0;
	if (argc > 1)
		ft_putnbr(argc - 1);
	else
		ft_putchar('0');
	ft_putchar('\n');
	return (0);
}
