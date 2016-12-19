/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:41 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/18 17:28:10 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <nbr.h>
#include <sys/types.h>
#include <stdlib.h>

int8_t			flg_handler_d(t_ft_printf *s)
{
	if (s->new.arr[0] != '-' && (s->flg_plus || s->flg_space))
		GRD(arr_insertat(&s->new, 0, s->flg_plus ? "+" : " ", 1) == -1, -1);
	return (1);
}

static intmax_t	get_signed_input(t_ft_printf *s)
{
	if (s->int_len_mod == 0)
		return (va_arg(*s->ap, int));
	else if (s->int_len_mod == 1)
		return ((signed char)va_arg(*s->ap, int));
	else if (s->int_len_mod == 2)
		return ((short)va_arg(*s->ap, int));
	else if (s->int_len_mod == 3)
		return (va_arg(*s->ap, long));
	else if (s->int_len_mod == 4)
		return (va_arg(*s->ap, long long));
	else if (s->int_len_mod == 5)
		return (va_arg(*s->ap, intmax_t));
	else if (s->int_len_mod == 6)
		return (va_arg(*s->ap, ssize_t));
	else
		return (0);
}

int8_t			ft_printf_d(t_ft_printf *s)
{
	intmax_t	tmp;

	GRD1(s->flg_hash, free(s->ret.arr), -1);
	tmp = get_signed_input(s);
	GRD1((s->new.arr = (uint8_t *)ft_itoa(tmp)) == 0, free(s->ret.arr), -1);
	s->new.len = ft_strlen((char *)s->new.arr);
	s->new.cap = s->new.len + 1;
	GRD2(flg_handler_d(s) == -1, free(s->new.arr), free(s->ret.arr), -1);
	GRD2(arr_insertat(&s->ret, s->ret.len, s->new.arr, s->new.len) == -1
		, free(s->new.arr), free(s->ret.arr), -1);
	arr_dtr(&s->new);
	++s->fmt;
	return (1);
}
