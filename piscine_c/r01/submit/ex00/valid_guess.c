/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_guess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:28:11 by nweizman          #+#    #+#             */
/*   Updated: 2016/07/24 19:28:16 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	in_box(char **grid, int r_box, int c_box, char num)
{
	int row;
	int col;

	row = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			if (grid[row + (3 * r_box)][col + (3 * c_box)] == num)
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

int	in_col(char **grid, int row, int col, char num)
{
	row = 0;
	while (row < 9)
	{
		if (grid[row][col] == num)
			return (0);
		row++;
	}
	return (1);
}

int	in_row(char **grid, int row, int col, char num)
{
	col = 0;
	while (col < 9)
	{
		if (grid[row][col] == num)
			return (0);
		col++;
	}
	return (1);
}

int	valid_guess(char **grid, int row, int col, char num)
{
	if (in_row(grid, row, col, num) && in_col(grid, row, col, num)
		&& in_box(grid, row / 3, col / 3, num))
		return (1);
	return (0);
}
