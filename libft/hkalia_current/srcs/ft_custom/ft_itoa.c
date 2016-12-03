/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:37:10 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/16 17:22:32 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_custom.h>
#include <ft_stdlib.h>
#include <stdbool.h>
#include <stdlib.h>

char	*ft_itoa(intmax_t src)
{
	short				src_len;
	bool				flg_neg;
	uintmax_t			src_cpy;
	char				*ret;

	src_len = ft_nbrlen(src);
	if (!(ret = ft_calloc(src_len + 1, sizeof(char))))
		return (0);
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
