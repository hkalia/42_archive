#include <stdlib.h>
#include <unistd.h>

unsigned char	*ft_memnew(int size)
{
	unsigned char	*ret;
	int				i;

	ret = (unsigned char *)malloc(sizeof(unsigned char) * size);
	i = 0;
	while (i < size)
	{
		ret[i] = 0;
		++i;
	}
	return (ret);
}

void	brainfuck(char *src, int src_len)
{
	unsigned char	*mem;
	unsigned char	*mem_cpy;
	int				i;
	int				loop;
	unsigned char	tmp;

	mem = ft_memnew(2048);
	mem_cpy = mem;
	i = 0;
	while (i < src_len)
	{
		switch (src[i])
		{
			case '>' :
				mem_cpy++;
				break ;
			case '<' :
				mem_cpy--;
				break ;
			case '+' :
				(*mem_cpy)++;
				break ;
			case '-' :
				(*mem_cpy)--;
				break ;
			case '.' :
				write(1, mem_cpy, 1);
				break ;
			case '[' :
				break ;
			case ']' :
				if (*mem_cpy != 0)
				{
					loop = 1;
					while (loop > 0)
					{
						tmp = src[--i];
						if (tmp == '[')
							loop--;
						else if (tmp == ']')
							loop++;
					}
				}
				break ;
		}
		++i;
	}
	free(mem);
}

int		ft_strlen(const char *src)
{
	const char	*src_cpy;

	src_cpy = src;
	while (*src_cpy)
		++src_cpy;
	return (src_cpy - src);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		brainfuck(argv[1], ft_strlen(argv[1]));
	else
		write(1, "\n", 1);
	return (0);
}
