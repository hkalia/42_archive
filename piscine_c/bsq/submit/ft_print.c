/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfriedri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 14:42:00 by mfriedri          #+#    #+#             */
/*   Updated: 2016/08/03 18:00:42 by mfriedri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	draw_square(char **grid)
{
	int		j;
	int		i;
	char	**temp;

	temp = grid;
	j = 0;
	while (j < g_size)
	{
		i = 0;
		while (i < g_size)
		{
			temp[g_loc_y + j][g_loc_x + i] = g_fill_sq;
			i++;
		}
		j++;
	}
}

void	print_grid(char **grid)
{
	int i;
	int j;

	j = 0;
	while (j < g_height)
	{
		i = 0;
		while (i < g_width)
		{
			write(1, &grid[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}
