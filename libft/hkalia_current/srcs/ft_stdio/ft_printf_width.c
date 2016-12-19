/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:33:36 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/18 16:02:21 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <stdlib.h>
#include <unistd.h>

int8_t	width_handler_csp(t_ft_printf *s)
{
	char	*tmp;
	int		diff;

	if ((diff = s->int_width - s->new.len) > 0)
	{
		GRD((tmp = (char *)malloc(sizeof(char) * diff)) == 0, -1);
		ft_memset(tmp, s->flg_zero ? '0' : ' ', diff);
		GRD1(arr_insertat(&s->new, s->flg_minus ? s->new.len : 0
			, tmp, diff) == -1, free(tmp), -1);
		free(tmp);
		return (0);
	}
	return (0);
}

int8_t	ft_printf_width(t_ft_printf *s)
{
	if (*s->fmt == '*')
	{
		s->int_width = va_arg(*s->ap, int);
		++s->fmt;
		if (s->int_width < 0)
		{
			s->flg_minus = 1;
			s->int_width = -(s->int_width);
		}
	}
	else
	{
		while (*s->fmt >= '0' && *s->fmt <= '9')
		{
			s->int_width = 10 * s->int_width + ((*s->fmt) - '0');
			++s->fmt;
		}
	}
	return (0);
}
