/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_solution_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 20:18:40 by hkalia            #+#    #+#             */
/*   Updated: 2016/07/24 20:18:44 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		valid_guess(char **grid, int row, int col, char num);

int		find_empty_square2(char **grid, int *row, int *col)
{
	int rowcnt;
	int columcnt;

	rowcnt = 8;
	while (rowcnt >= 0)
	{
		columcnt = 8;
		while (columcnt >= 0)
		{
			if (grid[rowcnt][columcnt] == '.')
			{
				*row = rowcnt;
				*col = columcnt;
				return (1);
			}
			columcnt--;
		}
		rowcnt--;
	}
	return (0);
}

int		sudoku2(char **grid)
{
	int		row;
	int		col;
	char	num;

	if (!find_empty_square2(grid, &row, &col))
		return (1);
	num = '9';
	while (num >= '1')
	{
		if (valid_guess(grid, row, col, num))
		{
			grid[row][col] = num;
			if (sudoku2(grid))
				return (1);
			grid[row][col] = '.';
		}
		num--;
	}
	return (0);
}

int		compare(char **grid, char **grid2)
{
	int		i;
	int		j;
	char	endl;

	endl = '\n';
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (grid[i][j] != grid2[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
