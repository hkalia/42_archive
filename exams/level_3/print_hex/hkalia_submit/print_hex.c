#include <unistd.h>

void	ft_putchar(char src)
{
	write(1, &src, 1);
}

int		ft_atoi(const char *str)
{
	int		flg_neg;
	long	nbr;

	while (*str == ' ' || *str == '\f' || *str == '\t'
			|| *str == '\n' || *str == '\r' || *str == '\v')
	   str++;
	flg_neg = (*str == '-' ? -1 : 1);
	str = ((*str == '-' || *str == '+') ? str + 1 : str);
	while (*str == '0')
		str++;
	nbr = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * flg_neg);
}

char	hex_conv(int src)
{
	if (src == 0)
		return ('0');
	if (src == 1)
		return ('1');
	if (src == 2)
		return ('2');
	if (src == 3)
		return ('3');
	if (src == 4)
		return ('4');
	if (src == 5)
		return ('5');
	if (src == 6)
		return ('6');
	if (src == 7)
		return ('7');
	if (src == 8)
		return ('8');
	if (src == 9)
		return ('9');
	if (src == 10)
		return ('a');
	if (src == 11)
		return ('b');
	if (src == 12)
		return ('c');
	if (src == 13)
		return ('d');
	if (src == 14)
		return ('e');
	if (src == 15)
		return ('f');
	return (0);
}

int		main(int argc, char **argv)
{
	int		src;
	char	n[8];
	int		i;

	i = 0;
	if (argc == 2)
	{
		src = ft_atoi(argv[1]);
		while (src)
		{
			n[i] = hex_conv(src % 16);
			src = src / 16;
			i++;
		}
		i--;
		while (i != -1)
		{
			ft_putchar(n[i]);
			i--;
		}
	}
	ft_putchar('\n');
	return (0);
}
