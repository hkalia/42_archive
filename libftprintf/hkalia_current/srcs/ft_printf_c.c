/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:10 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/01 12:23:50 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <stdlib.h>
#include <wchar.h>

static inline void	line_saver(char *s, wchar_t wchar)
{
	s[0] = (wchar >> 18) | 0xF0;
	s[1] = ((wchar >> 12) & 0x3F) | 0x80;
	s[2] = ((wchar >> 6) & 0x3F) | 0x80;
	s[3] = (wchar & 0x3F) | 0x80;
}

int					ft_printf_wctomb(char *s, wchar_t wchar)
{
	if (s == 0)
		return (0);
	if (wchar < 0x80)
		s[0] = wchar;
	else if (wchar < 0x800)
	{
		s[0] = (wchar >> 6) | 0xC0;
		s[1] = (wchar & 0x3F) | 0x80;
	}
	else if (wchar - 0xD800U < 0x800)
		return (-1);
	else if (wchar < 0x10000)
	{
		s[0] = (wchar >> 12) | 0xE0;
		s[1] = ((wchar >> 6) & 0x3F) | 0x80;
		s[2] = (wchar & 0x3F) | 0x80;
	}
	else if (wchar < 0x110000)
		line_saver(s, wchar);
	else
		return (-1);
	return (ft_printf_strlen(s));
}

static int8_t		ft_printf_c_l(va_list arg, t_ft_printf *s)
{
	size_t	i;

	GRD((i = ft_printf_wctomb(s->new.ptr, va_arg(arg, wint_t))) == -1, -1);
	if ((s->new.len = i) == 0)
		s->new.len = 1;
	return (0);
}

int8_t				ft_printf_c(t_ft_printf_arr *ret, const char **fmt
								, va_list arg, t_ft_printf *s)
{
	unsigned char	tmp;

	GRD1(!(s->len_mod == 0 || s->len_mod == 3), ft_printf_arr_dtr(ret), -1);
	GRD1(ft_printf_arr_init(&s->new, 10) == -1, ft_printf_arr_dtr(ret), -1);
	if (s->len_mod == 3)
		GRD2(ft_printf_c_l(arg, s) == -1, ft_printf_arr_dtr(&s->new)
			, ft_printf_arr_dtr(ret), -1);
	else
	{
		tmp = (unsigned char)va_arg(arg, int);
		GRD2(ft_printf_arr_insertm(&s->new, 0, &tmp, 1) == -1
			, ft_printf_arr_dtr(&s->new), ft_printf_arr_dtr(ret), -1);
	}
	GRD2(ft_printf_width_h(s) == -1, ft_printf_arr_dtr(&s->new)
		, ft_printf_arr_dtr(ret), -1);
	return (ft_printf_line(ret, fmt, s));
}

int8_t				ft_printf_cap_c(t_ft_printf_arr *ret, const char **fmt
								, va_list arg, t_ft_printf *s)
{
	s->len_mod = 3;
	return (ft_printf_c(ret, fmt, arg, s));
}
