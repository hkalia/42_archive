/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:10:00 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/18 16:05:56 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <stdlib.h>

int8_t	ft_printf_h(t_ft_printf *s)
{
	GRD1(s->int_len_mod != 0, arr_dtr(&s->ret), -1);
	s->int_len_mod = 2;
	++s->fmt;
	return (0);
}
