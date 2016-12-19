/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cap_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:38 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/18 17:29:02 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <nbr.h>
#include <stdlib.h>

int8_t	ft_printf_cap_x(t_ft_printf *s)
{
	uintmax_t	tmp;

	tmp = get_input(s);
	GRD1((s->new.arr = (uint8_t *)ft_itoa_base(tmp, 16, "0123456789ABCDEF"))
		== 0, free(s->ret.arr), -1);
	s->new.len = ft_strlen((char *)s->new.arr);
	s->new.cap = s->new.len + 1;
	GRD2(arr_insertat(&s->ret, s->ret.len, s->new.arr, s->new.len) == -1
		, free(s->new.arr), free(s->ret.arr), -1);
	arr_dtr(&s->new);
	++s->fmt;
	return (1);
}
