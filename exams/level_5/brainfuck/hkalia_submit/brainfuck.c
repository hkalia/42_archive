#include <unistd.h>

#define MEM_SIZE 4096

unsigned char mem[MEM_SIZE];
unsigned char *memp = mem;

void	brainfuck(char *src)
{
	int		i;
	int		loop;

	i = 0;
	while (src[i])
	{
		if (src[i] == '>')
			++memp;
		else if (src[i] == '<')
			--memp;
		else if (src[i] == '+')
			++*memp;
		else if (src[i] == '-')
			--*memp;
		else if (src[i] == '.')
			write(1, memp, 1);
		else if (src[i] == '[' && *memp == 0)
		{
			loop = 1;
			while (loop != 0)
			{
				++i;
				if (src[i] == '[')
					++loop;
				else if (src[i] == ']')
					--loop;
			}
		}
		else if (src[i] == ']' && *memp != 0)
		{
			loop = 1;
			while (loop != 0)
			{
				--i;
				if (src[i] == ']')
					++loop;
				else if (src[i] == '[')
					--loop;
			}
		}
		++i;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		brainfuck(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
