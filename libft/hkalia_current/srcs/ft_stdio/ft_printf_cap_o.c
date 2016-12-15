/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cap_o.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:29 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/15 15:12:18 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>

int8_t	ft_printf_cap_o(t_arr *ret, const char **fmt,
						va_list *ap, t_ft_printf *state)
{
	state->int_len_mod = 3;
	return (ft_printf_o(ret, fmt, ap, state));
}
