/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:49 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/19 14:53:54 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <nbr.h>
#include <ft_string.h>
#include <stdlib.h>

static int8_t	dot_handler_p(t_ft_printf *s)
{
	char	*tmp;
	int		diff;

	if (s->flg_dot == 1)
	{
		if (s->int_dot == 0)
		{
			GRD(arr_removeat(&s->new, 0, s->new.len) == -1, -1);
			return (0);
		}
		if ((diff = s->int_dot - s->new.len) > 0)
		{
			GRD((tmp = (char *)malloc(sizeof(char) * diff)) == 0, -1);
			ft_memset(tmp, '0', diff);
			GRD1(arr_insertat(&s->new, 0, tmp, diff) == -1, free(tmp), -1);
			free(tmp);
			return (0);
		}
	}
	return (0);
}

static int8_t	width_handler_p(t_ft_printf *s)
{
	char	*tmp;
	int		diff;
	int8_t	flg;

	if ((diff = s->int_width - s->new.len) > 0)
	{
		flg = s->flg_zero == 1 ? 2 : 0;
		GRD((tmp = (char *)malloc(sizeof(char) * diff)) == 0, -1);
		ft_memset(tmp, s->flg_zero ? '0' : ' ', diff);
		GRD1(arr_insertat(&s->new, s->flg_minus ? s->new.len : 0 + flg
			, tmp, diff) == -1, free(tmp), -1);
		free(tmp);
		return (0);
	}
	return (0);
}

int8_t			ft_printf_p(t_ft_printf *s)
{
	uintmax_t	tmp;

	tmp = (uintmax_t)va_arg(*s->ap, void *);
	GRD1((s->new.arr = (uint8_t *)ft_itoa_base(tmp, 16, "0123456789abcdef"))
		== 0, free(s->ret.arr), -1);
	s->new.len = ft_strlen((char *)s->new.arr);
	s->new.cap = s->new.len + 1;
	GRD2(dot_handler_p(s) == -1, free(s->new.arr), free(s->ret.arr), -1);
	GRD2(arr_insertat(&s->new, 0, "0x", 2) == -1, free(s->new.arr)
		, free(s->ret.arr), -1);
	GRD2(width_handler_p(s) == -1, free(s->new.arr), free(s->ret.arr), -1);
	GRD2(arr_insertat(&s->ret, s->ret.len, s->new.arr, s->new.len) == -1
		, free(s->new.arr), free(s->ret.arr), -1);
	arr_dtr(&s->new);
	++s->fmt;
	return (1);
}
