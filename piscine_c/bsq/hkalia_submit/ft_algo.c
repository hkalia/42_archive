/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfriedri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 14:42:00 by mfriedri          #+#    #+#             */
/*   Updated: 2016/08/03 18:00:42 by mfriedri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		get_char_index(int y)
{
	int temp;
	int count;

	count = 0;
	temp = y;
	while (temp != 0)
	{
		temp /= 10;
		count++;
	}
	return (count);
}

int		check_square(char **grid, int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j < g_size)
	{
		i = g_size - 1;
		while (i >= 0)
		{
			if (grid[y + j][x + i] == g_empty_sq)
				i--;
			else
				return (i);
		}
		j++;
	}
	return (-1);
}

void	set_loc(int i, int j)
{
	g_loc_x = i;
	g_loc_y = j;
	g_size++;
}

void	check_grid(char **grid)
{
	int i;
	int j;
	int peg;

	j = 0;
	g_loc_y = 0;
	g_loc_x = 0;
	g_size = 1;
	while (j < g_height)
	{
		i = 0;
		while (i < g_width)
		{
			peg = check_square(grid, i, j);
			if (peg == -1)
				set_loc(i, j);
			else
				i += peg + 1;
		}
		j++;
	}
	g_size--;
	draw_square(grid);
	print_grid(grid);
}
