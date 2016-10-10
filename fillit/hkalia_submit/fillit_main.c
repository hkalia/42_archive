/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 15:25:03 by dmclaugh          #+#    #+#             */
/*   Updated: 2016/10/09 20:48:29 by dmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

char	**create_compare(void)
{
	char	**ret;

	if (!(ret = ft_tblnew(18, 13)))
		return (0);
	ret[0] = "####";
	ret[1] = "#...#...#...#";
	ret[2] = "#...###";
	ret[3] = "##..#...#";
	ret[4] = "###...#";
	ret[5] = "#...#..##";
	ret[6] = "#.###";
	ret[7] = "#...#...##";
	ret[8] = "###.#";
	ret[9] = "##...#...#";
	ret[10] = "##..##";
	ret[11] = "##.##";
	ret[12] = "#...##...#";
	ret[13] = "#..###";
	ret[14] = "#...##..#";
	ret[15] = "###..#";
	ret[16] = "#..##...#";
	ret[17] = "##...##";
	ret[18] = "#..##..#";
	return (ret);
}

char	*validate3(char **src_tbl)
{
	char	*ret;
	char	**compare;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!(ret = ft_strnew(26)))
		return (0);
	if (!(compare = create_compare()))
		return (0);
	while (src_tbl[i])
	{
		while (compare[j])
		{
			if (ft_strequ(src_tbl[i], compare[j]))
			{
				ret[k] = j + '0';
				k++;
				j = 0;
				break ;
			}
			j++;
		}
		if (j == 0)
			i++;
		else
			return (0);
	}
	return (ret);
}

char	*validation_caller(char *src)
{
	int		src_len;
	int		line_cnt;
	int		blck_cnt;
	char	**src_tbl;
	char	*tetri;

	src_len = 0;
	line_cnt = 0;
	blck_cnt = 0;
	validate1(src, &src_len, &line_cnt);
	if (src_len < 21 || line_cnt > 129)
		return (0);
	if (validate2(src, &blck_cnt))
		return (0);
	if (blck_cnt > 26)
		return (0);
	if (!(src_tbl = ft_tblnew(blck_cnt, 20)))
		return (0);
	assign_tbl(src_tbl, src);
	if (tbl_trim(src_tbl))
	{
		ft_tbldel(src_tbl);
		return (0);
	}
	if (!(tetri = validate3(src_tbl)))
	{
		ft_tbldel(src_tbl);
		return(0);
	}
	ft_tbldel(src_tbl);
	return (tetri);
}

int		main_caller(char *file)
{
	int		fd;
	char	*src;
	char	*tetri;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (1);
	if (!(src = ft_strnew(545)))
	{
		close(fd);
		return (1);
	}
	if (read(fd, src, 545) == -1)
	{
		close(fd);
		ft_strdel(&src);
		return (1);
	}
	if (read(fd, src, 1) != 0)
	{
		close(fd);
		ft_strdel(&src);
		return (1);
	}
	close(fd);
	if (!(tetri = validation_caller(src)))
	{
		ft_strdel(&src);
		return (1);
	}
	ft_putstr(tetri);
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
		return(1);
	}
	exit(0);
	return(0);
}
