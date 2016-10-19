/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 15:25:03 by dmclaugh          #+#    #+#             */
/*   Updated: 2016/10/19 10:27:45 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	while (recursor(board, tetarray, 0, 0))
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

int		*validation_caller(char *src)
{
	int		src_len;
	int		line_cnt;
	int		blck_cnt;
	char	**src_tbl;
	int		*tetri;

	src_len = 0;
	line_cnt = 0;
	blck_cnt = 0;
	validate1(src, &src_len, &line_cnt);
	if (src_len < 20 || line_cnt > 129)
		return (0);
	if (validate2(src, &blck_cnt) || blck_cnt > 26)
		return (0);
	if (!(src_tbl = ft_tblnew(blck_cnt, 20)))
		return (0);
	assign_tbl(src_tbl, src);
	if (tbl_trim(src_tbl) || (!(tetri = validate3(src_tbl))))
	{
		ft_tbldel(src_tbl);
		return (0);
	}
	ft_tbldel(src_tbl);
	return (tetri);
}

int		cleanup(int directives, int fd, char *src)
{
	if (directives == 1 || directives == 3)
		close(fd);
	if (directives == 2 || directives == 3)
		ft_strdel(&src);
	return (1);
}

int		main_caller(char *file)
{
	int		fd;
	char	*src;
	int		*tetri;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (1);
	if (!(src = ft_strnew(545)))
		return (cleanup(1, fd, src));
	if (read(fd, src, 545) == -1)
		return (cleanup(3, fd, src));
	if (read(fd, src, 1) != 0)
		return (cleanup(3, fd, src));
	close(fd);
	if (!(tetri = validation_caller(src)))
		return (cleanup(2, fd, src));
	ft_strdel(&src);
	if (solve_caller(tetri))
	{
		free(tetri);
		return (1);
	}
	free(tetri);
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(1);
		return (1);
	}
	if (main_caller(argv[1]))
	{
		ft_putstr("error\n");
		exit(1);
		return (1);
	}
	exit(0);
	return (0);
}
