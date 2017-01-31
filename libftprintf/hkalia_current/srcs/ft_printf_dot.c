/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:50:33 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/31 14:07:02 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <ft_string.h>
#include <stdlib.h>

int8_t	ft_printf_dot_h_ux(t_ft_printf *s)
{
	char	*tmp;
	int		diff;

	if (s->flgs & 0x20 && s->dot == 0 && s->new.ptr[0] == '0')
	{
		GRD(ft_printf_arr_removem(&s->new, 0, s->new.len) == -1, -1);
		return (0);
	}
	if (s->flgs & 0x20 && (diff = s->dot - s->new.len) > 0)
	{
		GRD((tmp = malloc(sizeof(char) * diff)) == 0, -1);
		ft_memset(tmp, '0', diff);
		GRD1(ft_printf_ft_printf_arr_insertat(&s->new, 0, tmp, diff) == -1, free(tmp)
			, -1);
		free(tmp);
		return (0);
	}
	return (0);
}

int8_t	ft_printf_dot(t_ft_printf_arr *ret, const char **fmt, va_list arg
						, t_ft_printf *s);)
{
	++*fmt;
	s->flgs |= 0x20;
	if (**fmt == '*')
	{
		s->dot = va_arg(arg, int);
		++*fmt;
		if (s->dot < 0)
		{
			s->dot = 0;
			s->flgs &= ~0x20;
		}
	}
	else
	{
		while (**fmt >= '0' && **fmt <= '9')
		{
			s->dot = 10 * s->dot + ((**fmt) - '0');
			++*fmt;
		}
	}
	return (0);
}
