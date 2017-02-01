/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:54 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/01 12:28:28 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <stdlib.h>

int8_t	ft_printf_dot_h_ux(t_ft_printf *s)
{
	char	*tmp;
	int		diff;

	if (s->flgs & 0x20 && s->dot == 0 && s->new.ptr[0] == '0')
	{
		GRD(ft_printf_arr_removem(&s->new, 0, s->new.len) == -1, -1);
		return (0);
	}
	if (s->flgs & 0x20 && (diff = s->dot - s->new.len) > 0)
	{
		GRD((tmp = malloc(sizeof(char) * diff)) == 0, -1);
		ft_printf_memset(tmp, '0', diff);
		GRD1(ft_printf_arr_insertm(&s->new, 0, tmp, diff) == -1, free(tmp), -1);
		free(tmp);
		return (0);
	}
	return (0);
}

int8_t	ft_printf_u(t_ft_printf_arr *ret, const char **fmt, va_list arg
							, t_ft_printf *s)
{
	uintmax_t	tmp;

	tmp = ft_printf_len_mod_oux(arg, s);
	GRD1((s->new.ptr = ft_printf_itoa_base(tmp, 10, "0123456789")) == 0
			, ft_printf_arr_dtr(ret), -1);
	s->new.len = ft_printf_strlen(s->new.ptr);
	s->new.cap = s->new.len + 1;
	GRD2(ft_printf_dot_h_ux(s) == -1, ft_printf_arr_dtr(&s->new)
		, ft_printf_arr_dtr(ret), -1);
	GRD2(ft_printf_width_h(s) == -1, ft_printf_arr_dtr(&s->new)
		, ft_printf_arr_dtr(ret), -1);
	return (ft_printf_line(ret, fmt, s));
}

int8_t	ft_printf_cap_u(t_ft_printf_arr *ret, const char **fmt
								, va_list arg, t_ft_printf *s)
{
	s->len_mod = 3;
	return (ft_printf_u(ret, fmt, arg, s));
}
