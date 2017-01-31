/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:33:36 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/31 14:13:49 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <stdlib.h>

int8_t	ft_printf_width_h_o(t_ft_printf *s)
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

int8_t	ft_printf_width(t_ft_printf_arr *ret, const char **fmt
									, va_list arg, t_ft_printf *s)
{
	(void)ret;
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
