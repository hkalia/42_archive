/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:44 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/23 11:25:30 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>

int8_t	ft_printf_i(t_arr *ret, const char **fmt,
					va_list *ap, t_ft_printf *state)
{
	return (ft_printf_d(ret, fmt, ap, state));
}
