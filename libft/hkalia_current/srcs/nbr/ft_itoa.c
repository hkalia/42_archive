/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:37:10 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 12:05:59 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nbr.h>
#include <mem.h>
#include <stdbool.h>

char	*ft_itoa(intmax_t src)
{
	short				src_len;
	bool				flg_neg;
	uintmax_t			src_cpy;
	char				*ret;

	src_len = ft_nbrlen(src);
	GRD((ret = ft_memalloc(src_len + 1)) == 0, 0);
	flg_neg = (src < 0) ? 1 : 0;
	src_cpy = src;
	src_cpy = flg_neg ? -src_cpy : src_cpy;
	while (--src_len)
	{
		ret[src_len] = src_cpy % 10 + '0';
		src_cpy = src_cpy / 10;
	}
	ret[src_len] = flg_neg ? '-' : src_cpy % 10 + '0';
	return (ret);
}
