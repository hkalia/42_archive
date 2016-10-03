/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 16:47:05 by hkalia            #+#    #+#             */
/*   Updated: 2016/07/24 16:47:08 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	**collect(char argc, char **argv);
int		valid_guess(char **grid, int row, int col, char num);
int		find_empty_square2(char **grid, int *row, int *col);
int		sudoku2(char **grid);
int		compare(char **grid, char **grid2);

void	print(char **grid)
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
			write(1, &(grid[i][j]), 1);
			if (j + 1 < 9)
				write(1, " ", 1);
			j++;
		}
		write(1, &endl, 1);
		i++;
	}
}

int		find_empty_square(char **grid, int *row, int *col)
{
	int rowcnt;
	int columcnt;

	rowcnt = 0;
	while (rowcnt < 9)
	{
		columcnt = 0;
		while (columcnt < 9)
		{
			if (grid[rowcnt][columcnt] == '.')
			{
				*row = rowcnt;
				*col = columcnt;
				return (1);
			}
			columcnt++;
		}
		rowcnt++;
	}
	return (0);
}

int		sudoku(char **grid)
{
	int		row;
	int		col;
	char	num;

	if (!find_empty_square(grid, &row, &col))
		return (1);
	num = '1';
	while (num <= '9')
	{
		if (valid_guess(grid, row, col, num))
		{
			grid[row][col] = num;
			if (sudoku(grid))
				return (1);
			grid[row][col] = '.';
		}
		num++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char **grid;
	char **grid2;

	if ((grid = collect(argc, argv)) == 0)
		return (write(1, "Error\n", 6));
	if (sudoku(grid) != 1)
		return (write(1, "Error\n", 6));
	grid2 = collect(argc, argv);
	sudoku2(grid2);
	if (compare(grid, grid2) == 1)
		print(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}
