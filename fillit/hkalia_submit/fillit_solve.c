/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 15:24:32 by dmclaugh          #+#    #+#             */
/*   Updated: 2016/10/08 15:25:43 by dmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	iterrow(int row, int col)
{
	if (row < col)
		return (++row);
	else
		return (row);
}

int	itercol(int row, int col)
{
	if (col <= row)
		return (++col);
	else
		return (col);
}

int	write_tet(char **board, char **tet, int row, int col)
{
	int i;

	i = 0;
	while (*tet[i])
	{
		if (*tet[i] != '.')
			board[row][col] = *tet[i];
		if (*tet[i] == '.')
		{

		}
	}
	return (1);
}

int	place_tet(char **board, char **tet, int row, int col)
{
	int i;
	int	wrow;
	int	wcol;

	i = 0;
	wrow = row;
	wcol = col;
	while (*tet[i])
	{
		if (*tet[i] == '.')
		{

		}
		if (*tet[i] != '.' && board[wrow][wcol] != '.')
			return (place_tet(board, tet, iterrow(wrow, wcol), itercol(wrow, wcol)));
	}
	return (write_tet(board, tet, row, col));
}

int	fill_square(char **board, char *tet)
{
	if (tet)
	{
		if (!(board[row][col]))
			if(expand_board(board))
				return (0);
		if (place_tet(board, tet, 0, 0))
			fill_square(board, ++tet);
		else
			
	}
	else
		return (0);
}
