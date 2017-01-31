/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_len_mod.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:15:16 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/30 15:21:54 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int8_t	ft_printf_hh(t_ft_printf_arr *ret, const char **fmt, va_list arg
					, t_ft_printf *s)
{
	(void)arg;
	GRD1(s->len_mod != 0, ft_printf_arr_dtr(ret), -1);
	s->len_mod = 1;
	++*fmt;
	return (0);
}
int8_t	ft_printf_h(t_ft_printf_arr *ret, const char **fmt, va_list arg
					, t_ft_printf *s)
{
	(void)arg;
	GRD1(s->len_mod != 0, ft_printf_arr_dtr(ret), -1);
	s->len_mod = 2;
	++*fmt;
	return (0);
}

int8_t	ft_printf_l(t_ft_printf_arr *ret, const char **fmt, va_list arg
					, t_ft_printf *s)
{
	(void)arg;
	if (*(*fmt + 1) == 'l')
		return (0);
	GRD1(s->len_mod != 0, ft_printf_arr_dtr(ret), -1);
	s->len_mod = 3;
	++*fmt;
	return (0);
}

int8_t	ft_printf_ll(t_ft_printf_arr *ret, const char **fmt, va_list arg
					, t_ft_printf *s)
{
	(void)arg;
	GRD1(s->len_mod != 0, ft_printf_arr_dtr(ret), -1);
	s->len_mod = 4;
	++*fmt;
	return (0);
}

int8_t	ft_printf_j(t_ft_printf_arr *ret, const char **fmt, va_list arg
					, t_ft_printf *s)
{
	(void)arg;
	GRD1(s->len_mod != 0, ft_printf_arr_dtr(ret), -1);
	s->len_mod = 5;
	++*fmt;
	return (0);
}

int8_t	ft_printf_z(t_ft_printf_arr *ret, const char **fmt, va_list arg
					, t_ft_printf *s)
{
	(void)arg;
	GRD1(s->len_mod != 0, ft_printf_arr_dtr(ret), -1);
	s->len_mod = 6;
	++*fmt;
	return (0);
}
