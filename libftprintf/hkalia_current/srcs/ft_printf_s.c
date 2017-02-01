/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:51 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/01 12:24:55 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <stdlib.h>
#include <wchar.h>

static int8_t	null_handler(t_ft_printf_arr *ret, const char **fmt
							, t_ft_printf *s)
{
	if (!(s->flgs & 0x10))
		GRD1(ft_printf_arr_appendm(&s->new, "(null)", 6) == -1
			, ft_printf_arr_dtr(ret), -1);
	GRD2(ft_printf_width_h(s) == -1, ft_printf_arr_dtr(&s->new)
		, ft_printf_arr_dtr(ret), -1);
	return (ft_printf_line(ret, fmt, s));
}

static int8_t	ft_printf_s_l(wchar_t *src, t_ft_printf_arr *new)
{
	char	*new2;
	int		tmp;
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i] != 0)
		++i;
	GRD((new2 = malloc(sizeof(wint_t) * i)) == 0, -1);
	ft_printf_bzero(new2, sizeof(wint_t) * i);
	i = 0;
	j = 0;
	while (src[i] != 0)
	{
		GRD1((tmp = ft_printf_wctomb(&new2[j], src[i])) == -1, free(new2), -1);
		j += tmp;
		++i;
	}
	GRD1(ft_printf_arr_insertm(new, 0, new2, j) == -1, free(new2), -1);
	free(new2);
	return (0);
}

int8_t			ft_printf_s(t_ft_printf_arr *ret, const char **fmt, va_list arg
							, t_ft_printf *s)
{
	wchar_t	*tmp;
	char	*tmp1;

	GRD1(ft_printf_arr_init(&s->new, 10) == -1, ft_printf_arr_dtr(ret), -1);
	if (s->len_mod == 3)
	{
		GRD((tmp = va_arg(arg, wchar_t *)) == 0, null_handler(ret, fmt, s));
		GRD2(ft_printf_s_l(tmp, &s->new) == -1, ft_printf_arr_dtr(&s->new)
			, ft_printf_arr_dtr(ret), -1);
	}
	else
	{
		GRD((tmp1 = va_arg(arg, char *)) == 0, null_handler(ret, fmt, s));
		GRD2(ft_printf_arr_insertm(&s->new, 0, tmp1, ft_printf_strlen(tmp1))
			== -1, ft_printf_arr_dtr(&s->new), ft_printf_arr_dtr(ret), -1);
	}
	if (s->flgs & 0x20 && s->new.len > (size_t)s->dot)
		GRD2(ft_printf_arr_removem(&s->new, s->dot, s->new.len - s->dot) == -1
			, ft_printf_arr_dtr(&s->new), ft_printf_arr_dtr(ret), -1);
	GRD2(ft_printf_width_h(s) == -1, ft_printf_arr_dtr(&s->new)
		, ft_printf_arr_dtr(ret), -1);
	return (ft_printf_line(ret, fmt, s));
}

int8_t			ft_printf_cap_s(t_ft_printf_arr *ret, const char **fmt
								, va_list arg, t_ft_printf *s)
{
	s->len_mod = 3;
	return (ft_printf_s(ret, fmt, arg, s));
}
