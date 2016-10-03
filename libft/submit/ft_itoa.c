/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:37:10 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/29 11:24:35 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_itoa(int src)
{
	int		nbr_len;
	int		flg_neg;
	long	src_cpy;
	char	*dst;

	flg_neg = (src < 0) ? 1 : 0;
	nbr_len = ft_nbrlen(src);
	if (!(dst = (char *)malloc(sizeof(char) * (nbr_len + 1))))
		return (NULL);
	src_cpy = src;
	src_cpy = (flg_neg) ? -src_cpy : src_cpy;
	dst[nbr_len] = '\0';
	nbr_len--;
	while (nbr_len)
	{
		dst[nbr_len] = src_cpy % 10 + '0';
		src_cpy = src_cpy / 10;
		nbr_len--;
	}
	dst[nbr_len] = (flg_neg) ? '-' : (src_cpy % 10 + '0');
	return (dst);
}
