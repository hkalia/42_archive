/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solve_tetsetup.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 16:00:03 by dmclaugh          #+#    #+#             */
/*   Updated: 2016/10/18 16:10:27 by dmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*createtet3(int tet, char *str)
{
	if (tet == 9)
		return (ft_strcpy(str, "##...#...#"));
	else if (tet == 10)
		return (ft_strcpy(str, "##..##"));
	else if (tet == 11)
		return (ft_strcpy(str, ".##.##"));
	else if (tet == 12)
		return (ft_strcpy(str, "#...##...#"));
	else if (tet == 13)
		return (ft_strcpy(str, ".#..###"));
	else if (tet == 14)
		return (ft_strcpy(str, "#...##..#"));
	else if (tet == 15)
		return (ft_strcpy(str, "###..#"));
	else if (tet == 16)
		return (ft_strcpy(str, ".#..##...#"));
	else if (tet == 17)
		return (ft_strcpy(str, "##...##"));
	return (ft_strcpy(str, ".#..##..#"));
}

char	*createtet2(int tet)
{
	char	*str;

	if (!(str = ft_strnew(20)))
		return (0);
	if (tet == 0)
		return (ft_strcpy(str, "####"));
	else if (tet == 1)
		return (ft_strcpy(str, "#...#...#...#"));
	else if (tet == 2)
		return (ft_strcpy(str, "#...###"));
	else if (tet == 3)
		return (ft_strcpy(str, "##..#...#"));
	else if (tet == 4)
		return (ft_strcpy(str, "###...#"));
	else if (tet == 5)
		return (ft_strcpy(str, ".#...#..##"));
	else if (tet == 6)
		return (ft_strcpy(str, "..#.###"));
	else if (tet == 7)
		return (ft_strcpy(str, "#...#...##"));
	else if (tet == 8)
		return (ft_strcpy(str, "###.#"));
	else
		return (createtet3(tet, str));
}

char	**createtet(int *tetindex)
{
	char	**tetarray;
	int		size;
	int		i;

	size = 0;
	while (tetindex[size] != 42)
		size++;
	if (!(tetarray = (char **)malloc(sizeof(char *) * (size + 1))))
		return (0);
	tetarray[size] = 0;
	i = 0;
	while (tetindex[i] != 42)
	{
		if (!(tetarray[i] = createtet2(tetindex[i])))
		{
			ft_tbldel(tetarray);
			return (0);
		}
		i++;
	}
	return (convertarray(tetarray));
}
