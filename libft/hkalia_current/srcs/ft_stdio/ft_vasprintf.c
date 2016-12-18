/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:52:30 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/17 17:13:21 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <stdlib.h>
#include <nbr.h>
#include <unistd.h>

#define LEN1 37
#define LEN2 3

static char		g_spec[LEN1][LEN2] = {
	{"-"}, {"+"}, {" "}, {"#"}
	, {"0"}, {"*"}, {"1"}, {"2"}
	, {"3"}, {"4"}, {"5"}, {"6"}
	, {"7"}, {"8"}, {"9"}, {"."}
	, {"hh"}, {"h"}, {"l"}, {"ll"}
	, {"j"}, {"z"}, {"d"}, {"i"}
	, {"o"}, {"u"}, {"x"}, {"X"}
	, {"D"}, {"O"}, {"U"}, {"C"}
	, {"c"}, {"S"}, {"s"}, {"p"}, {"%"}};

static int8_t	(*g_funcs[LEN1]) (t_arr *ret, const char **fmt
										, va_list *ap, t_ft_printf *state) = {
	ft_printf_flags, ft_printf_flags, ft_printf_flags, ft_printf_flags
	, ft_printf_flags, ft_printf_width, ft_printf_width, ft_printf_width
	, ft_printf_width, ft_printf_width, ft_printf_width, ft_printf_width
	, ft_printf_width, ft_printf_width, ft_printf_width, ft_printf_dot
	, ft_printf_hh, ft_printf_h, ft_printf_l, ft_printf_ll
	, ft_printf_j, ft_printf_z, ft_printf_d, ft_printf_i
	, ft_printf_o, ft_printf_u, ft_printf_x, ft_printf_cap_x
	, ft_printf_cap_d, ft_printf_cap_o, ft_printf_cap_u, ft_printf_cap_c
	, ft_printf_c, ft_printf_cap_s, ft_printf_s, ft_printf_p, ft_printf_mod};

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

static int8_t	dispatcher(t_arr *ret, const char **fmt, va_list *ap)
{
	t_ft_printf	state;
	t_arr		new;
	size_t		i;
	int8_t		r;

	ft_bzero(&state, sizeof(t_ft_printf));
	i = 0;
	while (i < LEN1)
	{
		if (**fmt == g_spec[i][0] && check(*fmt, g_spec[i]))
		{
			GRD((r = (*g_funcs[i])(ret, fmt, ap, &state)) == -1, -1);
			if (r > 0)
				return (r);
		}
		++i;
	}
	ft_bzero(&new, sizeof(t_arr));
	GRD1(arr_insertat(&new, 0, *fmt, 1) == -1, free(ret->arr), -1);
	GRD2(width_handler_csp(&state, &new) == -1, free(new.arr), free(ret->arr)
		, -1);
	GRD2(arr_insertat(ret, ret->len, new.arr, new.len) == -1, free(new.arr)
			, free(ret->arr), -1);
	free(new.arr);
	++*fmt;
	return (1);
}

static int		iterator(char **final, const char *fmt, va_list *ap)
{
	t_arr	ret;
	size_t	i;
	int8_t	r;

	i = ft_strlen(fmt);
	GRD(arr_init(&ret, i == 0 ? 10 : i) == -1, -1);
	while (*fmt)
	{
		i = 0;
		while (fmt[i] && fmt[i] != '%')
			++i;
		GRD(arr_insertat(&ret, ret.len, fmt, i) == -1, -1);
		fmt += i;
		if (fmt[0] == '%')
		{
			if (*(++fmt) == 0)
				break ;
			GRD((r = dispatcher(&ret, &fmt, ap)) == -1, -1);
			if (r == 2)
				break ;
		}
	}
	GRD1((*final = arr_tostr(&ret)) == 0, free(ret.arr), -1);
	return ((int)ret.len);
}

int				ft_vasprintf(char **ret, const char *fmt, va_list *ap)
{
	int		r;

	if (fmt == 0 || *fmt == 0 || ret == 0)
		return (0);
	*ret = 0;
	if (ft_strchr(fmt, '%') == 0)
		return ((*ret = ft_strdup(fmt)) ? (int)ft_strlen(fmt) : -1);
	r = iterator(ret, fmt, ap);
	return (r);
}
