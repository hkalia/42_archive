/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_tbl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 14:41:50 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/08 20:42:51 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_tblnew(int len)
{
	int		i;
	char	**new;

	if (!(new = (char **)malloc(sizeof(char *) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		if (!(new[i] = ft_strnew(20)))
			return (0);
		i++;
	}
	new[i] = 0;
	return (new);
}

void	ft_puttbl(char **tbl)
{
	int		i;

	i = 0;
	while (tbl[i])
	{
		ft_putendl(tbl[i]);
		i++;
	}
}

void	ft_tbldel(char **tbl)
{
	int		i;

	i = 0;
	while (tbl[i])
	{
		free(tbl[i]);
		i++;
	}
	free(tbl);
	tbl = 0;
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
