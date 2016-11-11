/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cap_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:20 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/10 14:55:43 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>

int		ft_printf_cap_c(char **ret, const char **fmt,
						va_list *ap, t_printf_parse *parse_state)
{
	parse_state->int_len_mod = 3;
	return (ft_printf_c(ret, fmt, ap, parse_state));
}
