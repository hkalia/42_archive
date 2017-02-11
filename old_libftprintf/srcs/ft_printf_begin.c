/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_begin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:33:36 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/01 12:25:55 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <stdlib.h>

int8_t	ft_printf_line(t_ft_printf_arr *ret, const char **fmt, t_ft_printf *s)
{
	GRD2(ft_printf_arr_appendarr(ret, &s->new) == -1, ft_printf_arr_dtr(&s->new)
		, ft_printf_arr_dtr(ret), -1);
	ft_printf_arr_dtr(&s->new);
	++*fmt;
	return (1);
}

int8_t	ft_printf_flags(t_ft_printf_arr *ret, const char **fmt, va_list arg
						, t_ft_printf *s)
{
	(void)ret;
	(void)arg;
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
		else if (**fmt == ' ' && !(s->flgs & 0x2))
			s->flgs |= 0x4;
		else if (**fmt == '#')
			s->flgs |= 0x8;
		else if (**fmt == '0' && !(s->flgs & 0x1))
			s->flgs |= 0x10;
		++*fmt;
	}
	return (0);
}

int8_t	ft_printf_width(t_ft_printf_arr *ret, const char **fmt
									, va_list arg, t_ft_printf *s)
{
	(void)ret;
	s->width = 0;
	if (**fmt == '*')
	{
		s->width = va_arg(arg, int);
		++*fmt;
		if (s->width < 0)
		{
			s->flgs |= 0x1;
			s->width = -(s->width);
		}
	}
	else
	{
		while (**fmt >= '0' && **fmt <= '9')
		{
			s->width = 10 * s->width + ((**fmt) - '0');
			++*fmt;
		}
	}
	return (0);
}

int8_t	ft_printf_dot(t_ft_printf_arr *ret, const char **fmt, va_list arg
						, t_ft_printf *s)
{
	(void)ret;
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

int8_t	ft_printf_width_h(t_ft_printf *s)
{
	char	*tmp;
	int		diff;

	if ((diff = s->width - s->new.len) > 0)
	{
		GRD((tmp = (char *)malloc(sizeof(char) * diff)) == 0, -1);
		ft_printf_memset(tmp, s->flgs & 0x10 ? '0' : ' ', diff);
		GRD1(ft_printf_arr_insertm(&s->new, s->flgs & 0x1 ? s->new.len : 0
			, tmp, diff) == -1, free(tmp), -1);
		free(tmp);
	}
	return (0);
}
