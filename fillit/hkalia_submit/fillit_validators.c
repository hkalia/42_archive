/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_validators.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 20:41:24 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/10 13:32:24 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int		validate2(char *src, int *blck_cnt)
{
	int		i;
	int		dot_cnt;
	int		line_cnt;

	i = 0;
	dot_cnt = 0;
	line_cnt = 0;
	while (src[i])
	{
		if (src[i] == '.' || src[i] == '#')
			dot_cnt++;
		if (src[i] == '\n' && (src[i + 1] != '\n' && src[i + 1] != '\0'))
		{
			if (dot_cnt != 4)
				return (1);
			else
				dot_cnt = 0;
		}
		if (src[i] == '\n' && (src[i - 1] == '.' || src[i - 1] == '#'))
			line_cnt++;
		if (src[i] == '\n' && (src[i + 1] == '\n' || src[i + 1] == '\0'))
		{
			if (line_cnt != 4)
				return (1);
			else
			{
				line_cnt = 0;
				(*blck_cnt)++;
			}
		}
		i++;
	}
	return (0);
}

void	validate1(char *src, int *src_len, int *line_cnt)
{
	int		i;

	i = 0;
	while (*src)
	{
		if (*src != '.' && *src != '#' && *src != '\n')
		{
			*src_len = 1;
			return ;
		}
		if (*src == '\n')
			(*line_cnt)++;
		src++;
		(*src_len)++;
	}
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
