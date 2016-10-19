/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solve_setup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:07:55 by dmclaugh          #+#    #+#             */
/*   Updated: 2016/10/18 16:09:57 by dmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 0	"####"			I
** 1	"#...#...#...#"	I
** 2	"#...###"		J
** 3	"##..#...#"		J
** 4	"###...#"		J
** 5	"#...#..##"		J
** 6	"#.###"			L
** 7	"#...#...##"	L
** 8	"###.#"			L
** 9	"##...#...#"	L
** 10	"##..##"		O
** 11	"##.##"			S
** 12	"#...##...#"	S
** 13	"#..###"		T
** 14	"#...##..#"		T
** 15	"###..#"		T
** 16	"#..##...#"		T
** 17	"##...##"		Z
** 18	"#..##..#"		Z
*/

#include "fillit.h"

char	**finishboard(char **board, int size, int str_size, int i)
{
	int		j;

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
			j++;
		}
		board[i][j + 1] = 'x';
		board[i][j + 2] = 'x';
		board[i][j + 3] = 'x';
		i++;
	}
	return (finishboard(board, size, str_size, i));
}

char	**convertarray(char **tetarray)
{
	int		i;
	int		j;

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

void	cleanup_board(char **board)
{
	int row;
	int col;

	row = 0;
	while (board[row])
	{
		col = 0;
		if (board[row][col] == 'x')
			board[row] = 0;
		else
		{
			while (board[row][col])
			{
				if (board[row][col] == 'x')
					board[row][col] = 0;
				++col;
			}
		}
		++row;
	}
}
