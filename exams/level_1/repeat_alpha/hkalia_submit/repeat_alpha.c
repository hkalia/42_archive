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

int		isalpha(int src)
{
	if ((src >= 'A' && src <= 'Z') || (src >= 'a' && src <= 'z'))
		return (1);
	return (0);
}

int		isupper(int src)
{
	if (src >= 'A' && src <= 'Z')
		return (1);
	return (0);
}

int		islower(int src)
{
	if (src >= 'a' && src <= 'z')
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (isalpha(argv[1][i]))
			{
				if (isupper(argv[1][i]))
				{
					j = 0;
					while (j <= (argv[1][i] - 'A'))
					{
						ft_putchar(argv[1][i]);
						j++;
					}
				}
				if (islower(argv[1][i]))
				{
					j = 0;
					while (j <= (argv[1][i] - 'a'))
					{
						ft_putchar(argv[1][i]);
						j++;
					}
				}
			}
			else
				ft_putchar(argv[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
