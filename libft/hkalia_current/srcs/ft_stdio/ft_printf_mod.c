/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:40:01 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/18 16:54:55 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <stdlib.h>

int8_t	ft_printf_mod(t_ft_printf *s)
{
	GRD1(arr_insertat(&s->new, 0, "%", 1) == -1, free(s->ret.arr), -1);
	GRD2(width_handler_csp(s) == -1, free(s->new.arr), free(s->ret.arr), -1);
	GRD2(arr_insertat(&s->ret, s->ret.len, s->new.arr, s->new.len) == -1
		, free(s->new.arr), free(s->ret.arr), -1);
	arr_dtr(&s->new);
	++s->fmt;
	return (1);
}
