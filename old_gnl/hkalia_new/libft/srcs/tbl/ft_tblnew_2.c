/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tblnew_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 12:28:10 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/12 11:11:18 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tbl.h>
#include <str.h>
#include <stdlib.h>

char	**ft_tblnew_2(int len, int str_len)
{
	int		i;
	char	**new;

	if (!(new = (char **)malloc(sizeof(char *) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		if (!(new[i] = ft_strnew(str_len)))
		{
			ft_tbldel(new);
			return (0);
		}
		i++;
	}
	new[i] = 0;
	return (new);
}
