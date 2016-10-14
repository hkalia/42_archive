/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 20:15:08 by dmclaugh          #+#    #+#             */
/*   Updated: 2016/10/12 19:38:43 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	removetet(char **board, char *tet)
{
	char	tmp;
	int		row;
	int		col;

	row = 0;
	while (*tet == '.')
		++tet;
	tmp = *tet;
	while (board[row])
	{
		col = 0;
		while (board[row][col])
		{
			if (board[row][col] == tmp)
				board[row][col] = '.';
			++col;
		}
		++row;
	}
}

void	writetet(char **board, char *tet, int row, int col)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (tet[i])
	{
		if (tet[i] != '.')
			board[row][col] = tet[i];
		++i;
		++col;
		++cnt;
		if (cnt == 4)
		{
			++row;
			col -= 4;
			cnt = 0;
		}
	}
}

int		checktet(char **board, char *tet, int row, int col)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (tet[i])
	{
		if (cnt == 4)
		{
			row++;
			cnt = 0;
			col -= 4;
		}
		if (tet[i] >= 'A' && tet[i] <= 'Z' && board[row][col] != '.')
			return (0);
		cnt++;
		col++;
		i++;
	}
	return (1);
}

int		recursor(char **board, char **tetarray, int row, int col)
{
	if (!*tetarray)
		return (0);
	while (board[row])
	{
		while (board[row][col])
		{
			if (checktet(board, *tetarray, row, col))
			{
				writetet(board, *tetarray, row, col);
				ft_puttbl(board);
				if (recursor(board, (1 + tetarray), 0, 0))
					removetet(board, *tetarray);
				else
					return (0);
			}
			++col;
		}
		++row;
		col = 0;
	}
	return (1);
}

int		solve_caller(int *tetindex)
{
	char	**tetarray;
	char	**board;
	int		size;

	size = find_board_size(tetindex);
	if (!(board = buildboard(size, size)))
		return (1);
	if (!(tetarray = createtet(tetindex)))
		return (1);
	while(recursor(board, tetarray, 0, 0))
	{
		++size;
		ft_tbldel(board);
		if (!(board = buildboard(size, size)))
			return (1);
	}

	cleanup_board(board);
	ft_puttbl(board);
	return (0);
}
