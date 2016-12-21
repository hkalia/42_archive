/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_j.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:11:13 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/18 16:08:31 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <stdlib.h>

int8_t	ft_printf_j(t_ft_printf *s)
{
	GRD1(s->int_len_mod != 0, free(s->ret.arr), -1);
	s->int_len_mod = 5;
	++s->fmt;
	return (0);
}
