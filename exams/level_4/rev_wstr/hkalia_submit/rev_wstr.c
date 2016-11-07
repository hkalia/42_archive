#include <unistd.h>

void	ft_putwrd(char *src)
{
	signed long long	i;

	i = 0;
	while (src[i] && src[i] != ' ')
		++i;
	write(1, src, i);
}

int		main(int argc, char **argv)
{
	signed long long	i;

	if (argc == 2)
	{
		i = 0;
		if (argv[1][0])
			while (argv[1][i])
				++i;
		if (i != 0)
		{
			while (i != -1)
			{
				if (argv[1][i] == ' ')
				{
					ft_putwrd(&argv[1][i + 1]);
					write(1, " ", 1);
				}
				--i;
			}
			ft_putwrd(&argv[1][i + 1]);
		}
	}
	write(1, "\n", 1);
	return (0);
}
