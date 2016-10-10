/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 20:15:08 by dmclaugh          #+#    #+#             */
/*   Updated: 2016/10/09 14:28:33 by dmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*buildrow(int size)
{
	char	*row;
	int		i;

	if (!(row = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		row[i] = '.';
		++i;
	}
	row[i] = 0;
	return (row);
}

char	**buildboard(int size)
{
	int		i;
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char) * (size + 1) * size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(tab[i] = buildrow(size)))
			return (NULL);
		++i;
	}
	tab[i] = 0;
	return (tab);
}

void	removetet(char **board, char *tet)
{
	int		row;
	int		col;
	char	*wipe;

	wipe = tet;
	while (*wipe == '.')
		++wipe;
	row = 0;
	while (*board[row])
	{
		col = 0;
		while (board[row][col])
		{
			if (board[row][col] == *wipe)
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
		if (board[row][col] == 0 || (tet[i] != '.' && board[row][col] != '.'))
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
