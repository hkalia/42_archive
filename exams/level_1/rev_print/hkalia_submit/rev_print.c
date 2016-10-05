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

int		ft_strlen(char *src)
{
	int		ret;

	ret = 0;
	while (src[ret])
		ret++;
	return (ret);
}

int		main(int argc, char **argv)
{
	int		i;

	if (argc == 2)
	{
		i = ft_strlen(argv[1]);
		i--;
		while (i != -1)
		{
			ft_putchar(argv[1][i]);
			i--;
		}
	}
	ft_putchar('\n');
	return (0);
}
