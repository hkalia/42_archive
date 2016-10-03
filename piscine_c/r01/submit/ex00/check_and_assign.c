/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 14:11:49 by rwu               #+#    #+#             */
/*   Updated: 2016/07/24 14:11:55 by rwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		checkgv(char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			if ((argv[i][j] >= '1' && argv[i][j] <= '9') || argv[i][j] == '.')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

char	**collect(char argc, char **argv)
{
	char	**sudoku;
	int		rowcnt;
	int		colcnt;

	rowcnt = 1;
	colcnt = 0;
	if (argc != 10 || (checkgv(argv) != 1))
		return (0);
	sudoku = (char**)malloc(sizeof(char*) * 10);
	while (rowcnt < argc)
	{
		colcnt = 0;
		sudoku[rowcnt - 1] = (char*)malloc(sizeof(char) * 10);
		while (colcnt <= 8)
		{
			sudoku[rowcnt - 1][colcnt] = argv[rowcnt][colcnt];
			colcnt++;
		}
		rowcnt++;
	}
	return (sudoku);
}
