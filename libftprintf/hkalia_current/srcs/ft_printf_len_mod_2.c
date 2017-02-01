/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_len_mod_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 09:29:34 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/01 10:08:53 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int8_t		ft_printf_z(t_ft_printf_arr *ret, const char **fmt, va_list arg
						, t_ft_printf *s)
{
	(void)arg;
	GRD1(s->len_mod != 0, ft_printf_arr_dtr(ret), -1);
	s->len_mod = 6;
	++*fmt;
	return (0);
}
