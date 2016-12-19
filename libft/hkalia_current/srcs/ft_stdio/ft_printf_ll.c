/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:13:57 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/18 16:07:54 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <stdlib.h>

int8_t	ft_printf_ll(t_ft_printf *s)
{
	GRD1(s->int_len_mod != 0, free(s->ret.arr), -1);
	s->int_len_mod = 4;
	s->fmt += 2;
	return (0);
}
