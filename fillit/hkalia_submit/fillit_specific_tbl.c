/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_specific_tbl.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 13:30:30 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/19 11:18:28 by dmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*dot_nl_trim2(char *new)
{
	int		i;

	i = 0;
	while (new[i])
		i++;
	i--;
	while (new[i] && new[i] != '#')
	{
		new[i] = '\0';
		i--;
	}
	return (new);
}

char	*dot_nl_trim(char *src)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (!(new = ft_strnew(16)))
		return (0);
	while (*src && *src != '#')
		src++;
	if (!src || *src == '\0')
		return (new);
	while (src[j])
	{
		if (src[j] != '\n')
		{
			new[i] = src[j];
			i++;
		}
		j++;
	}
	return (dot_nl_trim2(new));
}

int		tbl_trim(char **src_tbl)
{
	char	*tmp;
	int		i;

	i = 0;
	while (src_tbl[i])
	{
		if (!(tmp = dot_nl_trim(src_tbl[i])))
			return (1);
		if (tmp[0] == '\0')
		{
			free(tmp);
			return (1);
		}
		free(src_tbl[i]);
		src_tbl[i] = tmp;
		i++;
	}
	return (0);
}

void	assign_tbl(char **src_tbl, char *src)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (src[i])
	{
		if (src[i] == '\n' && src[i + 1] == '\n')
		{
			src_tbl[j][k] = src[i];
			i += 2;
			j++;
			k = 0;
		}
		src_tbl[j][k] = src[i];
		k++;
		i++;
	}
}

int		*nbrstrnew(int size, int stop)
{
	int		*ret;
	int		i;

	i = 0;
	if (!(ret = (int *)malloc(sizeof(int) * (size + 1))))
		return (0);
	while (i <= size)
	{
		ret[i] = stop;
		i++;
	}
	return (ret);
}
