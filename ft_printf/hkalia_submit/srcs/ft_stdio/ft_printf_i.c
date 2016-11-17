/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:44 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/16 16:10:51 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>

int		ft_printf_i(char **ret, const char **fmt,
					va_list *ap, t_printf_parse *parse_state)
{
	return (ft_printf_d(ret, fmt, ap, parse_state));
}
