/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:52:30 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/01 12:29:55 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define LEN1 39
#define LEN2 3

static char		g_spec[LEN1][LEN2] = {
	{"-"}, {"+"}, {" "}, {"#"}
	, {"0"}, {"*"}, {"1"}, {"2"}
	, {"3"}, {"4"}, {"5"}, {"6"}
	, {"7"}, {"8"}, {"9"}, {"*"}
	, {"."}, {"hh"}, {"h"}, {"l"}
	, {"ll"}, {"j"}, {"z"}, {"#"}
	, {"d"}, {"i"}, {"o"}, {"u"}
	, {"x"}, {"X"}, {"D"}, {"O"}
	, {"U"}, {"C"}, {"c"}, {"S"}
	, {"s"}, {"p"}, {"%"}};

static int8_t	(*g_funcs[LEN1]) (t_ft_printf_arr *ret, const char **fmt
									, va_list arg, t_ft_printf *s) = {
	ft_printf_flags, ft_printf_flags, ft_printf_flags, ft_printf_flags
	, ft_printf_flags, ft_printf_width, ft_printf_width, ft_printf_width
	, ft_printf_width, ft_printf_width, ft_printf_width, ft_printf_width
	, ft_printf_width, ft_printf_width, ft_printf_width, ft_printf_width
	, ft_printf_dot, ft_printf_hh, ft_printf_h, ft_printf_l
	, ft_printf_ll, ft_printf_j, ft_printf_z, ft_printf_flags
	, ft_printf_d, ft_printf_d, ft_printf_o, ft_printf_u
	, ft_printf_x, ft_printf_cap_x, ft_printf_cap_d, ft_printf_cap_o
	, ft_printf_cap_u, ft_printf_cap_c, ft_printf_c, ft_printf_cap_s
	, ft_printf_s, ft_printf_p, ft_printf_mod};

static bool		check(const char *fmt, char *spec)
{
	size_t	i;

	i = 0;
	while (fmt[i] != 0 && spec[i] != 0 && fmt[i] == spec[i])
		++i;
	if (spec[i] == 0 && i > 0)
		return (1);
	return (0);
}

static int8_t	dispatcher(t_ft_printf_arr *ret, const char **fmt, va_list arg
							, t_ft_printf *s)
{
	size_t		i;
	int8_t		r;

	ft_printf_bzero(s, sizeof(t_ft_printf));
	i = 0;
	while (i < LEN1)
	{
		if (**fmt == g_spec[i][0] && check(*fmt, g_spec[i]))
		{
			GRD((r = (*g_funcs[i])(ret, fmt, arg, s)) == -1, -1);
			if (r > 0)
				return (r);
		}
		++i;
	}
	GRD(**fmt == 0, 0);
	GRD1(ft_printf_arr_init(&s->new, 1) == -1, ft_printf_arr_dtr(ret), -1);
	GRD1(ft_printf_arr_append(&s->new, *fmt) == -1, ft_printf_arr_dtr(ret), -1);
	GRD2(ft_printf_width_h(s) == -1, ft_printf_arr_dtr(&s->new)
		, ft_printf_arr_dtr(ret), -1);
	return (ft_printf_line(ret, fmt, s));
}

static int		iterator(char **final, const char *fmt, va_list arg)
{
	t_ft_printf_arr	ret;
	t_ft_printf		s;
	size_t			i;

	ft_printf_bzero(&s, sizeof(t_ft_printf));
	GRD(ft_printf_arr_init(&ret, ft_printf_strlen(fmt) + 10) == -1, -1);
	while (*fmt)
	{
		i = 0;
		while (fmt[i] != 0 && fmt[i] != '%')
			++i;
		GRD(ft_printf_arr_appendm(&ret, fmt, i) == -1, -1);
		fmt += i;
		if (*fmt == '%')
		{
			if (*(++fmt) == 0)
				break ;
			GRD(dispatcher(&ret, &fmt, arg, &s) == -1, -1);
		}
	}
	GRD1((*final = ft_printf_arr_tostr(&ret)) == 0, ft_printf_arr_dtr(&ret)
		, -1);
	return ((int)ret.len);
}

int				ft_vasprintf(char **ret, const char *fmt, va_list arg)
{
	int			r;
	va_list		clone;

	if (fmt == 0 || *fmt == 0 || ret == 0)
		return (0);
	*ret = 0;
	if (ft_printf_strchr(fmt, '%') == 0)
	{
		GRD((*ret = ft_printf_strdup(fmt)) == 0, -1);
		return (ft_printf_strlen(fmt));
	}
	va_copy(clone, arg);
	r = iterator(ret, fmt, clone);
	va_end(clone);
	return (r);
}
