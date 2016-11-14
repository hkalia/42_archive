/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cap_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:33 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/13 11:42:37 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <ft_string.h>

int		ft_printf_cap_s(char **ret, const char **fmt,
						va_list *ap, t_printf_parse *parse_state)
{
	parse_state->int_len_mod = 3;
	return (ft_printf_s(ret, fmt, ap, parse_state));
}
