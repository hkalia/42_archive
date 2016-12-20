/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:51 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/19 13:18:07 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <ft_stdlib.h>
#include <stdlib.h>
#include <wchar.h>

static int8_t	null_handler(t_ft_printf *s)
{
	if (s->flg_zero == 0)
		GRD1(arr_insertat(&s->new, s->new.len, "(null)", 6) == -1
			, free(s->ret.arr), -1);
	GRD2(width_handler(s) == -1, free(s->new.arr), free(s->ret.arr)
		, -1);
	GRD2(arr_insertat(&s->ret, s->ret.len, s->new.arr, s->new.len) == -1
		, free(s->new.arr), free(s->ret.arr), -1);
	arr_dtr(&s->new);
	++s->fmt;
	return (1);
}

static int8_t	ft_printf_s_l(wchar_t *src, t_arr *new)
{
	char	*new2;
	int		tmp;
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i] != 0)
		++i;
	GRD((new2 = ft_calloc(i, sizeof(wint_t))) == 0, -1);
	i = 0;
	j = 0;
	while (src[i] != 0)
	{
		GRD1((tmp = ft_wctomb(&new2[j], src[i])) == -1, free(new2), -1);
		j += tmp;
		++i;
	}
	GRD1(arr_insertat(new, 0, new2, j) == -1, free(new2), -1);
	free(new2);
	return (0);
}

int8_t			ft_printf_s(t_ft_printf *s)
{
	wchar_t	*tmp;
	char	*tmp1;

	if (s->int_len_mod == 3)
	{
		GRD((tmp = va_arg(*s->ap, wchar_t *)) == 0, null_handler(s));
		GRD1(ft_printf_s_l(tmp, &s->new) == -1, free(s->ret.arr), -1);
	}
	else
	{
		GRD((tmp1 = va_arg(*s->ap, char *)) == 0, null_handler(s));
		GRD1(arr_insertat(&s->new, 0, tmp1, ft_strlen(tmp1)) == -1
			, free(s->ret.arr), -1);
	}
	if (s->flg_dot && s->new.len > (size_t)s->int_dot)
		GRD2(arr_removeat(&s->new, s->int_dot, s->new.len - s->int_dot) == -1
			, free(s->new.arr), free(s->ret.arr), -1);
	GRD2(width_handler(s) == -1, free(s->new.arr), free(s->ret.arr), -1);
	GRD2(arr_insertat(&s->ret, s->ret.len, s->new.arr, s->new.len) == -1
		, free(s->new.arr), free(s->ret.arr), -1);
	arr_dtr(&s->new);
	++s->fmt;
	return (1);
}
