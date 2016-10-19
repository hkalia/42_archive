/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 13:46:46 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/19 12:17:25 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#define MEM_SIZE 2048

char mem[MEM_SIZE] = {0};
char *memp = mem;

void	brainfuck(char *src)
{
	int 	i;
	int 	loop;

	i = 0;
	while (src[i] != 0)
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
	return 0;
}
