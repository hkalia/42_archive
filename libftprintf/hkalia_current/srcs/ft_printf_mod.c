/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:40:01 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/31 14:07:02 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <ft_string.h>
#include <stdlib.h>

int8_t	ft_printf_mod(t_ft_printf *s)
{
	GRD1(arr_init(&s->new, 1, 1) == -1, arr_dtr(&s->ret), -1);
	GRD1(ft_printf_arr_insertat(&s->new, 0, "%", 1) == -1, arr_dtr(&s->ret), -1);
	GRD2(width_handler(s) == -1, arr_dtr(&s->new), arr_dtr(&s->ret), -1);
	GRD2(ft_printf_arr_insertat(&s->ret, s->ret.len, s->new.arr, s->new.len) == -1
		, arr_dtr(&s->new), arr_dtr(&s->ret), -1);
	arr_dtr(&s->new);
	++s->fmt;
	return (1);
}
