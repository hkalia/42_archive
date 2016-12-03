/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cap_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:33 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/23 11:27:24 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <ft_string.h>

int8_t	ft_printf_cap_s(t_arr *ret, const char **fmt,
						va_list *ap, t_ft_printf *state)
{
	state->int_len_mod = 3;
	return (ft_printf_s(ret, fmt, ap, state));
}
