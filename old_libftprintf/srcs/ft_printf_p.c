/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:49 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/01 12:28:06 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <stdlib.h>

static int8_t	dot_h(t_ft_printf *s)
{
	char	*tmp;
	int		diff;

	if (s->flgs & 0x20)
	{
		if (s->dot == 0)
		{
			GRD(ft_printf_arr_removem(&s->new, 0, s->new.len) == -1, -1);
			return (0);
		}
		if ((diff = s->dot - s->new.len) > 0)
		{
			GRD((tmp = malloc(sizeof(char) * diff)) == 0, -1);
			ft_printf_memset(tmp, '0', diff);
			GRD1(ft_printf_arr_insertm(&s->new, 0, tmp, diff) == -1, free(tmp)
				, -1);
			free(tmp);
			return (0);
		}
	}
	return (0);
}

static int8_t	width_h(t_ft_printf *s)
{
	char	*tmp;
	int		diff;
	int8_t	flg;

	if ((diff = s->width - s->new.len) > 0)
	{
		flg = s->flgs & 0x10 ? 2 : 0;
		GRD((tmp = malloc(sizeof(char) * diff)) == 0, -1);
		ft_printf_memset(tmp, s->flgs & 0x10 ? '0' : ' ', diff);
		GRD1(ft_printf_arr_insertm(&s->new, s->flgs & 0x1 ? s->new.len : 0 + flg
			, tmp, diff) == -1, free(tmp), -1);
		free(tmp);
		return (0);
	}
	return (0);
}

int8_t			ft_printf_p(t_ft_printf_arr *ret, const char **fmt, va_list arg
							, t_ft_printf *s)
{
	uintmax_t	tmp;

	tmp = (uintmax_t)va_arg(arg, void *);
	GRD1((s->new.ptr = ft_printf_itoa_base(tmp, 16, "0123456789abcdef")) == 0
		, ft_printf_arr_dtr(ret), -1);
	s->new.len = ft_printf_strlen(s->new.ptr);
	s->new.cap = s->new.len + 1;
	GRD2(dot_h(s) == -1, ft_printf_arr_dtr(&s->new), ft_printf_arr_dtr(ret)
		, -1);
	GRD2(ft_printf_arr_insertm(&s->new, 0, "0x", 2) == -1
		, ft_printf_arr_dtr(&s->new), ft_printf_arr_dtr(ret), -1);
	GRD2(width_h(s) == -1, ft_printf_arr_dtr(&s->new), ft_printf_arr_dtr(ret)
		, -1);
	return (ft_printf_line(ret, fmt, s));
}

int8_t			ft_printf_mod(t_ft_printf_arr *ret, const char **fmt
								, va_list arg, t_ft_printf *s)
{
	(void)arg;
	GRD1(ft_printf_arr_init(&s->new, 1) == -1, ft_printf_arr_dtr(ret), -1);
	GRD1(ft_printf_arr_insertm(&s->new, 0, "%", 1) == -1
		, ft_printf_arr_dtr(ret), -1);
	GRD2(ft_printf_width_h(s) == -1, ft_printf_arr_dtr(&s->new)
		, ft_printf_arr_dtr(ret), -1);
	return (ft_printf_line(ret, fmt, s));
}
