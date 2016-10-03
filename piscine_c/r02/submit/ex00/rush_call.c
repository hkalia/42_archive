/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_call.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 21:39:04 by hkalia            #+#    #+#             */
/*   Updated: 2016/07/31 21:39:06 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_2.h"

int		find_x(char *str)
{
	int		x;

	x = 0;
	while (str[x] != '\n')
		x++;
	return (x);
}

int		find_y(char *str)
{
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			y++;
		i++;
	}
	return (y);
}

int		find_size(char **str)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\n')
		{
			j++;
			k++;
		}
		k++;
		i++;
	}
	return (k);
}

char	*convert(char **str)
{
	char	*str1;
	int		i;
	int		j;
	int		k;

	str1 = (char*)malloc(sizeof(char) * find_size(str) + 1);
	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\n')
		{
			str1[k] = str[i][j];
			j++;
			k++;
		}
		str1[k] = '\n';
		k++;
		i++;
	}
	return (str1);
}

void	print_res(int rush, int x, int y, int call)
{
	if (call > 0)
		ft_putstr(" || ");
	ft_putstr("[rush-0");
	ft_putnbr(rush);
	ft_putstr("] [");
	ft_putnbr(x);
	ft_putstr("] [");
	ft_putnbr(y);
	ft_putstr("]");
}
