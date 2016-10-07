#include <unistd.h>
#include <stdio.h>
void	ft_putchar(char src)
{
	write(1, &src, 1);
}

void	print_bits(unsigned char octet)
{
	int		i;
	int		j;

	i = (int)octet;
	j = 128;
/*	while (i < j)
	{
		ft_putchar('0');
		j = j / 2;
	}*/
	while (i)
	{
		if (i % 2 == 0)
			ft_putchar('0');
		else if (i % 2 == 1)
			ft_putchar('1');
		i = i / 2;
	}
}

int		main(void)
{
	unsigned char	c;

	c = 2;
	print_bits(c);
	return (0);
}
