#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *src)
{
	int		len;

	len = 0;
	while (src[len])
		++len;
	return (len);
}

char	*ft_strnew(int len)
{
	char	*ret;
	int		i;

	ret = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i <= len)
	{
		ret[i] = 0;
		++i;
	}
	return (ret);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (argc > 1)
	{
		i = 0;
		j = 0;
		while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
		{
			++j;
			++i;
		}
		while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
			++i;
		str = ft_strnew(i - j);
		k = 0;
		while (j < i)
		{
			str[k] = argv[1][j];
			++k;
			++j;
		}
		k = 0;
		j = 0;
		while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
				++i;
		while (1)
		{
			if (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
			{
				k = 1;
				while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				{
					write(1, &argv[1][i], 1);
					++i;
				}
			}
			while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
					++i;
			if (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				write(1, " ", 1);
			else
				break;
		}
		if (k)
			write(1, " ", 1);
		write(1, str, ft_strlen(str));
		free(str);
	}
	write(1, "\n", 1);
	return (0);
}
