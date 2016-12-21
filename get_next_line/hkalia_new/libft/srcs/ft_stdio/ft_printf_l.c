/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:14:04 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/18 17:27:17 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <stdlib.h>

int8_t	ft_printf_l(t_ft_printf *s)
{
	if (*(s->fmt + 1) == 'l')
		return (0);
	GRD1(s->int_len_mod != 0, free(s->ret.arr), -1);
	s->int_len_mod = 3;
	++s->fmt;
	return (0);
}
