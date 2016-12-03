/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tblnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 15:02:21 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/14 15:02:24 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_custom.h>
#include <stdlib.h>

char	**ft_tblnew(int len)
{
	int		i;
	char	**new;

	if (!(new = (char **)malloc(sizeof(char *) * (len + 1))))
		return (0);
	i = 0;
	while (i <= len)
	{
		new[i] = 0;
		i++;
	}
	return (new);
}
