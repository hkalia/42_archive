/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solve_setup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:07:55 by dmclaugh          #+#    #+#             */
/*   Updated: 2016/10/12 17:19:02 by dmclaugh         ###   ########.fr       */
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
