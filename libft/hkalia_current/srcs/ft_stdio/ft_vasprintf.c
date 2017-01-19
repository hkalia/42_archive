/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:52:30 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/19 14:44:35 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <stdlib.h>
#include <nbr.h>
#include <unistd.h>

#define LEN1 38
#define LEN2 3

static char		g_spec[LEN1][LEN2] = {
	{"-"}, {"+"}, {" "}, {"#"}
	, {"0"}, {"*"}, {"1"}, {"2"}
	, {"3"}, {"4"}, {"5"}, {"6"}
	, {"7"}, {"8"}, {"9"}, {"*"}
	, {"."}, {"hh"}, {"h"}, {"l"}
	, {"ll"}, {"j"}, {"z"}, {"d"}
	, {"i"}, {"o"}, {"u"}, {"x"}
	, {"X"}, {"D"}, {"O"}, {"U"}
	, {"C"}, {"c"}, {"S"}, {"s"}
	, {"p"}, {"%"}};

static int8_t	(*g_funcs[LEN1]) (t_ft_printf *s) = {
	ft_printf_flags, ft_printf_flags, ft_printf_flags, ft_printf_flags
	, ft_printf_flags, ft_printf_width, ft_printf_width, ft_printf_width
	, ft_printf_width, ft_printf_width, ft_printf_width, ft_printf_width
	, ft_printf_width, ft_printf_width, ft_printf_width, ft_printf_width
	, ft_printf_dot, ft_printf_hh, ft_printf_h, ft_printf_l
	, ft_printf_ll, ft_printf_j, ft_printf_z, ft_printf_d
	, ft_printf_d, ft_printf_o, ft_printf_u, ft_printf_x
	, ft_printf_cap_x, ft_printf_cap_d, ft_printf_cap_o, ft_printf_cap_u
	, ft_printf_cap_c, ft_printf_c, ft_printf_cap_s, ft_printf_s
	, ft_printf_p, ft_printf_mod};

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

static int8_t	dispatcher(t_ft_printf *s)
{
	size_t		i;
	int8_t		r;

	*s = (t_ft_printf){s->ret, s->fmt, s->ap, s->new
						, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	i = 0;
	while (i < LEN1)
	{
		if (*s->fmt == g_spec[i][0] && check(s->fmt, g_spec[i]))
		{
			GRD((r = (*g_funcs[i])(s)) == -1, -1);
			if (r > 0)
				return (r);
		}
		++i;
	}
	GRD1(arr_init(&s->new, 1, 1) == -1, arr_dtr(&s->ret), -1);
	GRD1(arr_insertat(&s->new, 0, s->fmt, 1) == -1, arr_dtr(&s->ret), -1);
	GRD2(width_handler(s) == -1, arr_dtr(&s->new), arr_dtr(&s->ret), -1);
	GRD2(arr_insertat(&s->ret, s->ret.len, s->new.arr, s->new.len) == -1
		, arr_dtr(&s->new), arr_dtr(&s->ret), -1);
	arr_dtr(&s->new);
	++s->fmt;
	return (1);
}

static int		iterator(char **final, const char *fmt, va_list *ap)
{
	t_ft_printf	s;
	size_t		i;

	ft_bzero(&s, sizeof(t_ft_printf));
	GRD(arr_init(&s.ret, ft_strlen(fmt) + 10, sizeof(char)) == -1, -1);
	s.fmt = fmt;
	s.ap = ap;
	while (*s.fmt)
	{
		i = 0;
		while (s.fmt[i] && s.fmt[i] != '%')
			++i;
		GRD(arr_insertat(&s.ret, s.ret.len, s.fmt, i) == -1, -1);
		s.fmt += i;
		if (s.fmt[0] == '%')
		{
			if (*(++s.fmt) == 0)
				break ;
			GRD(dispatcher(&s) == -1, -1);
		}
	}
	GRD1((*final = arr_tostr(&s.ret)) == 0, arr_dtr(&s.ret), -1);
	return ((int)s.ret.len);
}

int				ft_vasprintf(char **ret, const char *fmt, va_list *ap)
{
	int			r;

	if (fmt == 0 || *fmt == 0 || ret == 0)
		return (0);
	*ret = 0;
	if (ft_strchr(fmt, '%') == 0)
		return ((*ret = ft_strdup(fmt)) ? (int)ft_strlen(fmt) : -1);
	r = iterator(ret, fmt, ap);
	return (r);
}
