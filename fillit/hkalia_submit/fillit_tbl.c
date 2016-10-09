/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_tbl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 14:41:50 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/08 17:49:26 by hkalia           ###   ########.fr       */
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
