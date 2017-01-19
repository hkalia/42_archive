/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:41 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/19 14:36:17 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <nbr.h>
#include <sys/types.h>
#include <stdlib.h>

static int8_t	dot_handler_d(t_ft_printf *s)
{
	char	*tmp;
	int		diff;
	bool	flg_neg;

	if (s->flg_dot == 1 && s->int_dot == 0 && ((char *)s->new.arr)[0] == '0')
	{
		GRD(arr_removeat(&s->new, 0, s->new.len) == -1, -1);
		return (0);
	}
	flg_neg = ((char *)s->new.arr)[0] == '-' ? 1 : 0;
	if (s->flg_dot == 1 && (diff = s->int_dot - (s->new.len - flg_neg)) > 0)
	{
		GRD((tmp = (char *)malloc(sizeof(char) * diff)) == 0, -1);
		ft_memset(tmp, '0', diff);
		GRD1(arr_insertat(&s->new, 0 + flg_neg, tmp, diff) == -1, free(tmp)
			, -1);
		free(tmp);
		return (0);
	}
	return (0);
}

static int8_t	width_handler_d(t_ft_printf *s)
{
	char	*tmp;
	int		diff;
	bool	flg;

	if ((diff = s->int_width - s->new.len) > 0)
	{
		flg = s->flg_zero == 1 && (((char *)s->new.arr)[0] == '-'
							|| s->flg_space == 1 || s->flg_plus == 1) ? 1 : 0;
		GRD((tmp = (char *)malloc(sizeof(char) * diff)) == 0, -1);
		ft_memset(tmp, s->flg_zero ? '0' : ' ', diff);
		GRD1(arr_insertat(&s->new, s->flg_minus ? s->new.len : 0 + flg
			, tmp, diff) == -1, free(tmp), -1);
		free(tmp);
	}
	return (0);
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

	GRD1(s->flg_hash, arr_dtr(&s->ret), -1);
	tmp = get_signed_input(s);
	GRD1((s->new.arr = ft_itoa(tmp)) == 0, arr_dtr(&s->ret), -1);
	s->new.elm = 1;
	s->new.len = ft_strlen((char *)s->new.arr);
	s->new.cap = s->new.len + 1;
	if (s->flg_dot == 1 && s->flg_zero == 1)
		s->flg_zero = 0;
	GRD2(dot_handler_d(s) == -1, arr_dtr(&s->new), arr_dtr(&s->ret), -1);
	if (((char *)s->new.arr)[0] != '-' && (s->flg_plus || s->flg_space))
		GRD(arr_insertat(&s->new, 0, s->flg_plus ? "+" : " ", 1) == -1, -1);
	GRD2(width_handler_d(s) == -1, arr_dtr(&s->new), arr_dtr(&s->ret), -1);
	GRD2(arr_insertat(&s->ret, s->ret.len, s->new.arr, s->new.len) == -1
		, arr_dtr(&s->new), arr_dtr(&s->ret), -1);
	arr_dtr(&s->new);
	++s->fmt;
	return (1);
}
