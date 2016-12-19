/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:50:33 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/18 16:04:08 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>

int8_t	ft_printf_dot(t_ft_printf *s)
{
	++s->fmt;
	s->flg_dot = 1;
	if (*s->fmt == '*')
	{
		s->int_dot = va_arg(*s->ap, int);
		++s->fmt;
		if (s->int_dot < 0)
		{
			s->int_dot = 0;
			s->flg_dot = 0;
		}
	}
	else
	{
		while (*s->fmt >= '0' && *s->fmt <= '9')
		{
			s->int_dot = 10 * s->int_dot + ((*s->fmt) - '0');
			++s->fmt;
		}
	}
	return (0);
}
