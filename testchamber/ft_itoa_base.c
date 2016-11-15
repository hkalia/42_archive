/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:28:47 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/15 07:00:38 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_nbrlen_base(int value, int base)
{
	int	ret;

	ret = 0;
	if (value == 0)
		return (1);
	if (value < 0 && base == 10)
		++ret;
	while (value != 0)
	{
		value = value / base;
		++ret;
	}
	return (ret);
}

char	*ft_itoa_base(int value, int base)
{
	int		value_len;
	char	*ret;
	int		flg_neg;
	long	value_cpy;
	char	*spec = "0123456789ABCDEF";

	if (base == 0 || base == 1)
		return (0);
	value_len = ft_nbrlen_base(value, base);
	if (!(ret = (char *)malloc(sizeof(char) * (value_len + 1))))
		return (0);
	ret[value_len] = 0;
	flg_neg = (value < 0 && base == 10) ? 1 : 0;
	value_cpy = value;
	value_cpy = value_cpy < 0 ? -value_cpy : value_cpy;
	while (--value_len)
	{
		ret[value_len] = spec[value_cpy % base];
		value_cpy = value_cpy / base;
	}
	ret[value_len] = (flg_neg) ? '-' : spec[value_cpy % base];
	return (ret);
}
//
// int		main(int argc, char **argv)
// {
// 	if (argc == 3)
// 		printf("%s", ft_itoa_base(atoi(argv[1]), atoi(argv[2])));
// 	return (0);
// }
//
// int		main(void)
// {
// 	int		i;
// 	int		j;
//
// 	i = 0;
// 	while (i < 17)
// 	{
// 		j = 2147483647;
// 		printf("%d %d = %s\n", j, i, ft_itoa_base(j, i));
// 		if (i == 10)
// 			j = -2147483648;
// 		else
// 			j = -2147483647;
// 		printf("%d %d = %s\n", j, i, ft_itoa_base(j, i));
// 		++i;
// 	}
// 	return (0);
// }
//
// int		main(void)
// {
// 	int		i;
// 	int		j;
//
// 	i = 0;
// 	while (i < 17)
// 	{
// 		j = 0;
// 		while (j < 17)
// 		{
// 			printf("%s\n", ft_itoa_base(j, i));
// 			++j;
// 		}
// 		if (i == 10)
// 		{
// 			j = -j;
// 			while (j)
// 			{
// 				printf("%s\n", ft_itoa_base(j, i));
// 				++j;
// 			}
// 		}
// 		++i;
// 	}
// 	return (0);
// }
//
