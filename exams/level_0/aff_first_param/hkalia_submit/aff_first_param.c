#include <unistd.h>

void	ft_putchar(char src)
{
	write(1, &src, 1);
}

void	ft_putstr(char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		ft_putchar(src[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		ft_putstr(argv[1]);
	ft_putchar('\n');
	return (0);
}
