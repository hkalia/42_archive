/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:56 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/19 14:24:57 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <nbr.h>
#include <stdlib.h>

static int8_t	width_handler_x(t_ft_printf *s)
{
	char	*tmp;
	int		diff;
	int8_t	flg;

	if ((diff = s->int_width - s->new.len) > 0)
	{
		flg = s->flg_zero == 1 && s->flg_hash == 1 ? 2 : 0;
		GRD((tmp = (char *)malloc(sizeof(char) * diff)) == 0, -1);
		ft_memset(tmp, s->flg_zero ? '0' : ' ', diff);
		GRD1(arr_insertat(&s->new, s->flg_minus ? s->new.len : 0 + flg
			, tmp, diff) == -1, free(tmp), -1);
		free(tmp);
		return (0);
	}
	return (0);
}

int8_t			ft_printf_x(t_ft_printf *s)
{
	uintmax_t	tmp;

	tmp = get_input(s);
	GRD1((s->new.arr = ft_itoa_base(tmp, 16, "0123456789abcdef")) == 0
		, arr_dtr(&s->ret), -1);
	s->new.elm = 1;
	s->new.len = ft_strlen((char *)s->new.arr);
	s->new.cap = s->new.len + 1;
	GRD2(dot_handler_ux(s) == -1, arr_dtr(&s->new), arr_dtr(&s->ret), -1);
	if (s->flg_hash == 1 && tmp != 0)
		GRD2(arr_insertat(&s->new, 0, "0x", 2) == -1, arr_dtr(&s->new)
			, arr_dtr(&s->ret), -1);
	GRD2(width_handler_x(s) == -1, arr_dtr(&s->new), arr_dtr(&s->ret), -1);
	GRD2(arr_insertat(&s->ret, s->ret.len, s->new.arr, s->new.len) == -1
		, arr_dtr(&s->new), arr_dtr(&s->ret), -1);
	arr_dtr(&s->new);
	++s->fmt;
	return (1);
}
