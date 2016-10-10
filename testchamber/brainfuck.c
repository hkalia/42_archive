/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 13:46:46 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/10 15:32:28 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

unsigned char	*ft_memnew(int ret_len)
{
	unsigned char	*ret;
	int				i;
	
	i = 0;
	if (!(ret = (unsigned char *)malloc(sizeof(unsigned char) * (ret_len + 1))))
		return (0);
	while (i < ret_len)
	{
		ret[i] = 0;
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int				brainfuck(char *src, int src_len)
{
	unsigned char	*mem;
	unsigned char	cur;
	int				i;
	int				loop;

	if (!(mem = ft_memnew(2048)))
		return (1);
	i = 0;
	while (i < src_len)
	{
		switch (src[i])
		{
			case '>' :
				mem++;
				break ;
			case '<' :
				mem--;
				break ;
			case '+' :
				(*mem)++;
				break ;
			case '-' :
				(*mem)--;
				break ;
			case '.' :
				write(1, mem, 1);
				break ;
			case '[' :
				break ;
			case ']' :
				if (*mem)
				{
					loop = 1;
					while (loop > 0)
					{
						cur = src[--i];
						if (cur == '[')
							loop--;
						else if (cur == ']')
							loop++;
					}
				}
				break ;
		}
		i++;
	}
	return (0);
}

int				ft_strlen(char *src)
{
	int		len;
	
	len = 0;
	while (src[len])
		len++;
	return (len);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (brainfuck(argv[1], ft_strlen(argv[1])))
		{
			write(1, "MALLOC ERROR\n", 13);
			return (1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
