/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:40:20 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 13:10:58 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <str.h>
#include <mem.h>
#include <stdbool.h>
#include <stdlib.h>

static void		tbldel(char **tbl)
{
	size_t	i;

	i = 0;
	while (tbl[i])
	{
		free(tbl[i]);
		++i;
	}
	free(tbl);
	tbl = 0;
}

static char		*wrddup(const char *src, char src_x)
{
	int		wrd_len;
	char	*wrd;
	int		j;

	wrd_len = 0;
	while (src[wrd_len] && src[wrd_len] != src_x)
		++wrd_len;
	GRD((wrd = ft_strnew(wrd_len)) == 0, 0);
	j = 0;
	while (j < wrd_len)
	{
		wrd[j] = src[j];
		++j;
	}
	return (wrd);
}

static size_t	wrds(const char *src, char src_x)
{
	size_t	ret;
	bool	flg;

	ret = 0;
	flg = 0;
	while (*src)
	{
		if (*src == src_x)
			flg = 0;
		else
		{
			if (flg == 0)
				++ret;
			flg = 1;
		}
		++src;
	}
	return (ret);
}

char			**ft_strsplit(const char *src, char src_x)
{
	size_t	len;
	char	**tbl;
	size_t	i;
	bool	flg;

	GRD(src == 0, 0);
	len = wrds(src, src_x);
	GRD((tbl = ft_memalloc(sizeof(char *) * (len + 1))) == 0, 0);
	i = 0;
	flg = 0;
	while (*src && i < len)
	{
		if (*src == src_x)
			flg = 0;
		else
		{
			if (flg == 0)
				GRD1((tbl[i++] = wrddup(src, src_x)) == 0, tbldel(tbl), 0);
			flg = 1;
		}
		++src;
	}
	return (tbl);
}
