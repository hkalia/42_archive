/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:41 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/01 12:24:24 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <stdlib.h>
#include <stdbool.h>

static int8_t	width_h(t_ft_printf *s)
{
	char	*tmp;
	int		diff;
	bool	flg;

	if ((diff = s->width - s->new.len) > 0)
	{
		flg = s->flgs & 0x10 && (s->new.ptr[0] == '-' || s->flgs & 0x4
		|| s->flgs & 0x2) ? 1 : 0;
		GRD((tmp = malloc(sizeof(char) * diff)) == 0, -1);
		ft_printf_memset(tmp, s->flgs & 0x10 ? '0' : ' ', diff);
		GRD1(ft_printf_arr_insertm(&s->new, s->flgs & 0x1 ? s->new.len : 0 + flg
			, tmp, diff) == -1, free(tmp), -1);
		free(tmp);
	}
	return (0);
}

static int8_t	dot_h(t_ft_printf *s)
{
	char	*tmp;
	int		diff;
	bool	flg_neg;

	if (s->flgs & 0x20 && s->dot == 0 && s->new.ptr[0] == '0')
	{
		GRD(ft_printf_arr_removem(&s->new, 0, s->new.len) == -1, -1);
		return (0);
	}
	flg_neg = s->new.ptr[0] == '-' ? 1 : 0;
	if (s->flgs & 0x20 && (diff = s->dot - (s->new.len - flg_neg)) > 0)
	{
		GRD((tmp = malloc(sizeof(char) * diff)) == 0, -1);
		ft_printf_memset(tmp, '0', diff);
		GRD1(ft_printf_arr_insertm(&s->new, 0 + flg_neg, tmp, diff) == -1
			, free(tmp), -1);
		free(tmp);
		return (0);
	}
	return (0);
}

static intmax_t	len_mod_h(va_list arg, t_ft_printf *s)
{
	if (s->len_mod == 0)
		return (va_arg(arg, int));
	else if (s->len_mod == 1)
		return ((signed char)va_arg(arg, int));
	else if (s->len_mod == 2)
		return ((short)va_arg(arg, int));
	else if (s->len_mod == 3)
		return (va_arg(arg, long));
	else if (s->len_mod == 4)
		return (va_arg(arg, long long));
	else if (s->len_mod == 5)
		return (va_arg(arg, intmax_t));
	else if (s->len_mod == 6)
		return (va_arg(arg, ssize_t));
	else
		return (0);
}

int8_t			ft_printf_d(t_ft_printf_arr *ret, const char **fmt, va_list arg
							, t_ft_printf *s)
{
	intmax_t	tmp;

	tmp = len_mod_h(arg, s);
	GRD1((s->new.ptr = ft_printf_itoa(tmp)) == 0, ft_printf_arr_dtr(ret), -1);
	s->new.len = ft_printf_strlen(s->new.ptr);
	s->new.cap = s->new.len + 1;
	if (s->flgs & 0x20 && s->flgs & 0x10)
		s->flgs &= ~0x10;
	GRD2(dot_h(s) == -1, ft_printf_arr_dtr(&s->new), ft_printf_arr_dtr(ret)
		, -1);
	if (s->new.ptr[0] != '-' && (s->flgs & 0x2 || s->flgs & 0x4))
		GRD(ft_printf_arr_insert(&s->new, 0, s->flgs & 0x2 ? "+" : " ") == -1
			, -1);
	GRD2(width_h(s) == -1, ft_printf_arr_dtr(&s->new), ft_printf_arr_dtr(ret)
		, -1);
	return (ft_printf_line(ret, fmt, s));
}

int8_t			ft_printf_cap_d(t_ft_printf_arr *ret, const char **fmt
								, va_list arg, t_ft_printf *s)
{
	s->len_mod = 3;
	return (ft_printf_d(ret, fmt, arg, s));
}
