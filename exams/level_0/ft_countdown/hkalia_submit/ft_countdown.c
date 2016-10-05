#include <unistd.h>

void	ft_putchar(char src)
{
	write(1, &src, 1);
}

void	ft_putstr(char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		ft_putchar(src[i]);
		i++;
	}
}

int		main(void)
{
	char	s[] = "9876543210\n";

	ft_putstr(s);
	return (0);
}
