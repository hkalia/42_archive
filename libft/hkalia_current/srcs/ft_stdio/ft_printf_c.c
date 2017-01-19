/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:10 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/19 14:50:52 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <ft_stdlib.h>
#include <stdlib.h>
#include <wchar.h>

static int8_t	ft_printf_c_l(t_ft_printf *s)
{
	size_t	i;

	GRD((i = ft_wctomb((char *)s->new.arr, va_arg(*s->ap, wint_t))) == -1, -1);
	if ((s->new.len = i) == 0)
		s->new.len = 1;
	return (0);
}

int8_t			ft_printf_c(t_ft_printf *s)
{
	unsigned char	tmp;

	GRD1(!(s->int_len_mod == 0 || s->int_len_mod == 3), arr_dtr(&s->ret), -1);
	GRD1(arr_init(&s->new, 10, sizeof(char)) == -1, arr_dtr(&s->ret), -1);
	if (s->int_len_mod == 3)
		GRD2(ft_printf_c_l(s) == -1, arr_dtr(&s->new), arr_dtr(&s->ret), -1);
	else
	{
		tmp = (unsigned char)va_arg(*s->ap, int);
		GRD2(arr_insertat(&s->new, 0, &tmp, 1) == -1, arr_dtr(&s->new)
			, arr_dtr(&s->ret), -1);
	}
	GRD2(width_handler(s) == -1, arr_dtr(&s->new), arr_dtr(&s->ret), -1);
	GRD2(arr_insertat(&s->ret, s->ret.len, s->new.arr, s->new.len) == -1
		, arr_dtr(&s->new), arr_dtr(&s->ret), -1);
	arr_dtr(&s->new);
	++s->fmt;
	return (1);
}
