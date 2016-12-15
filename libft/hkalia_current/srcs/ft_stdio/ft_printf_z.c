/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_z.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:10:39 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/15 15:06:58 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <stdlib.h>

int8_t	ft_printf_z(t_arr *ret, const char **fmt,
					va_list *ap, t_ft_printf *state)
{
	(void)fmt;
	(void)ap;
	GRD1(state->int_len_mod != 0, free(ret->arr), -1);
	state->int_len_mod = 6;
	++*fmt;
	return (0);
}
