/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cap_o.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:29 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/16 16:12:55 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <ft_string.h>

int		ft_printf_cap_o(char **ret, const char **fmt,
						va_list *ap, t_printf_parse *parse_state)
{
	return (ft_printf_o(ret, fmt, ap, parse_state));
}
