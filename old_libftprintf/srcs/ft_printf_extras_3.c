/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extras_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 12:23:38 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/01 12:13:44 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <stdlib.h>
#include <stdbool.h>

static short	ft_printf_nbrlen(intmax_t src)
{
	short	ret;

	if (src == 0)
		return (1);
	ret = src < 0 ? 1 : 0;
	while (src != 0)
	{
		src = src / 10;
		++ret;
	}
	return (ret);
}

char			*ft_printf_itoa(intmax_t src)
{
	short		src_len;
	bool		flg_neg;
	uintmax_t	src_cpy;
	char		*ret;

	src_len = ft_printf_nbrlen(src);
	GRD((ret = malloc(sizeof(char) * (src_len + 1))) == 0, 0);
	ft_printf_bzero(ret, src_len + 1);
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

static short	ft_nbrlen_base(uintmax_t src, short base)
{
	short	ret;

	ret = 0;
	if (src == 0)
		return (1);
	while (src != 0)
	{
		src = src / base;
		++ret;
	}
	return (ret);
}

char			*ft_printf_itoa_base(uintmax_t src, short base
									, const char *spec)
{
	short	src_len;
	char	*ret;

	if (base < 2)
		return (0);
	src_len = ft_nbrlen_base(src, base);
	GRD((ret = malloc(sizeof(char) * (src_len + 1))) == 0, 0);
	ft_printf_bzero(ret, src_len + 1);
	while (--src_len)
	{
		ret[src_len] = spec[src % base];
		src = src / base;
	}
	ret[src_len] = spec[src % base];
	return (ret);
}
