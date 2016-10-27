/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tblnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 12:28:10 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/14 12:28:17 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_custom.h>
#include <stdlib.h>

char	**ft_tblnew2(int len, int str_len)
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
