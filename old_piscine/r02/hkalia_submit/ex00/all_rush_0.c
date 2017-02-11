/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_rush_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 21:39:10 by hkalia            #+#    #+#             */
/*   Updated: 2016/07/31 21:39:11 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_2.h"

char	**rush00(int x, int y)
{
	char	**str;
	int		tmp;
	int		i;

	tmp = y;
	str = (char**)malloc(sizeof(char*) * (y + 1));
	i = 0;
	if (x > 0 && y > 0)
	{
		str[i] = ft_printline(x, 'o', '-', 'o');
		i++;
		y--;
		while (y > 1)
		{
			str[i] = ft_printline(x, '|', ' ', '|');
			i++;
			y--;
		}
		if (y == 1)
			str[i] = ft_printline(x, 'o', '-', 'o');
	}
	if (tmp != 1)
		i++;
	str[i] = 0;
	return (str);
}

char	**rush01(int x, int y)
{
	char	**str;
	int		tmp;
	int		i;

	tmp = y;
	str = (char**)malloc(sizeof(char*) * (y + 1));
	i = 0;
	if (x > 0 && y > 0)
	{
		str[i] = ft_printline(x, '/', '*', '\\');
		i++;
		y--;
		while (y > 1)
		{
			str[i] = ft_printline(x, '*', ' ', '*');
			i++;
			y--;
		}
		if (y == 1)
			str[i] = ft_printline(x, '\\', '*', '/');
	}
	if (tmp != 1)
		i++;
	str[i] = 0;
	return (str);
}

char	**rush02(int x, int y)
{
	char	**str;
	int		tmp;
	int		i;

	tmp = y;
	str = (char**)malloc(sizeof(char*) * (y + 1));
	i = 0;
	if (x > 0 && y > 0)
	{
		str[i] = ft_printline(x, 'A', 'B', 'A');
		i++;
		y--;
		while (y > 1)
		{
			str[i] = ft_printline(x, 'B', ' ', 'B');
			i++;
			y--;
		}
		if (y == 1)
			str[i] = ft_printline(x, 'C', 'B', 'C');
	}
	if (tmp != 1)
		i++;
	str[i] = 0;
	return (str);
}

char	**rush03(int x, int y)
{
	char	**str;
	int		tmp;
	int		i;

	tmp = y;
	str = (char**)malloc(sizeof(char*) * (y + 1));
	i = 0;
	if (x > 0 && y > 0)
	{
		str[i] = ft_printline(x, 'A', 'B', 'C');
		i++;
		y--;
		while (y > 1)
		{
			str[i] = ft_printline(x, 'B', ' ', 'B');
			i++;
			y--;
		}
		if (y == 1)
			str[i] = ft_printline(x, 'A', 'B', 'C');
	}
	if (tmp != 1)
		i++;
	str[i] = 0;
	return (str);
}

char	**rush04(int x, int y)
{
	char	**str;
	int		tmp;
	int		i;

	tmp = y;
	str = (char**)malloc(sizeof(char*) * (y + 1));
	i = 0;
	if (x > 0 && y > 0)
	{
		str[i] = ft_printline(x, 'A', 'B', 'C');
		i++;
		y--;
		while (y > 1)
		{
			str[i] = ft_printline(x, 'B', ' ', 'B');
			i++;
			y--;
		}
		if (y == 1)
			str[i] = ft_printline(x, 'C', 'B', 'A');
	}
	if (tmp != 1)
		i++;
	str[i] = 0;
	return (str);
}
