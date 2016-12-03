/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:14:04 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/24 17:16:00 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>

int8_t	ft_printf_l(t_arr *ret, const char **fmt,
					va_list *ap, t_ft_printf *state)
{
	(void)fmt;
	(void)ap;
	if (*(*fmt + 1) == 'l')
		return (0);
	FT_GRD1(state->int_len_mod != 0, free(ret->arr), -1);
	state->int_len_mod = 3;
	++*fmt;
	return (0);
}
