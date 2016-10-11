/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 20:15:08 by dmclaugh          #+#    #+#             */
/*   Updated: 2016/10/10 19:29:17 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
char	*buildrow(int size)
{
	char	*row;
	int		i;

	if (!(row = (char *)malloc(sizeof(char) * size + 3)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		row[i] = '.';
		++i;
	}
	row[i] = 0;
	row[i + 1] = 0;
	row[i + 2] = 0;
	return (row);
}
*/
char	**buildboard(int size, int str_size)
{
	char	**board;
	int		i;
	int		j;

	i = 0;
	if (!(board = ft_tblnew(size, str_size + 3)))
		return (0);
	while (i < size)
	{
		j = 0;
		while (j < (str_size))
		{
			board[i][j] = '.';
			j++;
		}
		i++;
	}
	return (board);
}

void	removetet(char **board, char c)
{
	int		row;
	int		col;

	row = 0;
	while (*board[row])
	{
		col = 0;
		while (board[row][col])
		{
			if (board[row][col] == c)
				board[row][col] = '.';
			++col;
		}
		++row;
	}
}

void	writetet(char **board, char *tet, int row, int col)
{
	int		i;

	i = 0;
	while (tet[i])
	{
		if (tet[i] != '.')
			board[row][col] = tet[i];
		++i;
		++col;
		if (i % 4 == 0)
		{
			++row;
			col -= 3;
		}
	}
}

int		placetet(char **board, char *tet, int row, int col)
{
	int 	i;
	
	i = 0;
	while (tet[i] && *board[row])
	{
		if (tet[i] != '.' && board[row][col] != '.')
			return (0);
		++i;
		++col;
		if (i % 4 == 0)
		{
			++row;
			col -= 3;
		}
	}
	return (1);
}
