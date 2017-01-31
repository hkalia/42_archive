/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:34:41 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/31 14:07:02 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int8_t	ft_printf_flags(t_ft_printf_arr *ret, const char **fmt, va_list arg
						, t_ft_printf *s)
{
	while (**fmt && (**fmt == '-' || **fmt == '+' || **fmt == ' '
			|| **fmt == '#' || **fmt == '0'))
	{
		if (**fmt == '-')
		{
			s->flgs &= ~0x10;
			s->flgs |= 0x1;
		}
		else if (**fmt == '+')
		{
			s->flgs &= ~0x4;
			s->flgs |= 0x2;
		}
		else if (**fmt == ' ' && !s->flg_plus)
			s->flgs |= 0x4;
		else if (**fmt == '#')
			s->flgs |= 0x8;
		else if (**fmt == '0' && !s->flg_minus)
			s->flgs |= 10;
		++*fmt;
	}
	return (0);
}
