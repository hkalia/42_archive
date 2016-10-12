/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 20:15:08 by dmclaugh          #+#    #+#             */
/*   Updated: 2016/10/12 15:55:30 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**buildboard(int size, int str_size)
{
	char	**board;
	int		i;
	int		j;

	i = 0;
	if (!(board = ft_tblnew(size + 3, str_size + 3)))
		return (0);
	while (i < size)
	{
		j = 0;
		while (j < (str_size))
		{
			board[i][j] = '.';
			board[i][j + 1] = 'x';
			board[i][j + 2] = 'x';
			board[i][j + 3] = 'x';
			j++;
		}
		i++;
	}
	while (i < size + 3)
	{
		j = 0;
		while (j < (str_size + 3))
		{
			board[i][j] = 'x';
			j++;
		}
		i++;
	}
	return (board);
}

void	removetet(char **board, char *tet)
{
	char	temp;
	int		i;
	int		row;
	int		col;

	i = 0;
	while (tet[i] == '.')
		++i;
	temp = tet[i];
	row = 0;
	while (*board[row])
	{
		col = 0;
		while (board[row][col])
		{
			if (board[row][col] == temp)
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
/*
int		checktet(char **board, char *tet, int row, int col)
{
}
*/
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
	else if (tet == 9)
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

char	**createtet(int *tetindex)
{
	char	**tetarray;
	int		size;
	int		i;
	int		j;

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
	i = 0;
	while (tetarray[i])
	{
		j = 0;
		while (tetarray[i][j])
		{
			if (tetarray[i][j] == '#')
				tetarray[i][j] = ('A' + i);
			j++;
		}
		i++;
	}
	return (tetarray);
}

int		find_board_size(int *tetindex)
{
	int		i;
	int		j;

	i = 0;
	while (tetindex[i] != 42)
		i++;
	i = i * 4;
	j = 2;
	while (i > (j * j))
		j++;
	return (j);
}
/*
int		recursor(char **board, char **tetarray, int	row, int col)
{
	if (tetarray == 0)
		return (1);
	ft_puttbl(board);
	while (board[row])
	{
		while (board[row][col])
		{
			if (checktet(board, *tetarray, row, col))
			{
				writetet(board, *tetarray, row, col);
				if (recursor(board, tetarray++, 0, 0))
					return (1);
				removetet(board, *tetarray);
			}
			col++;
		}
		row++;
	}
	return (0);
}
*/
int		solve_caller(int *tetindex)
{
	char	**tetarray;
	char	**board;
	int		size;

	size = find_board_size(tetindex);
	if (!(board = buildboard(size , size)))
		return (1);
	if (!(tetarray = createtet(tetindex)))
		return (1);
	/*while(recursor(board, tetarray, 0, 0))
	{
		++size;
		ft_tbldel(board);
		if (!(board = buildboard(size, size)))
			return (1);
			}*/
	ft_puttbl(tetarray);
	/*ft_putstr("check\n");
	if (checktet(board, *tetarray, 0, 0))
		ft_putstr("hello");*/
	ft_puttbl(board);
	return (0);
}
