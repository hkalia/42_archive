/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:50:33 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/18 16:27:36 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <stdlib.h>

int8_t	dot_handler_ux(t_ft_printf *s)
{
	char	*tmp;
	int		diff;

	if (s->flg_dot == 1 && s->int_dot == 0 && ((char *)s->new.arr)[0] == '0')
	{
		GRD(arr_removeat(&s->new, 0, s->new.len) == -1, -1);
		return (0);
	}
	if (s->flg_dot == 1 && (diff = s->int_dot - s->new.len) > 0)
	{
		GRD((tmp = (char *)malloc(sizeof(char) * diff)) == 0, -1);
		ft_memset(tmp, '0', diff);
		GRD1(arr_insertat(&s->new, 0, tmp, diff) == -1, free(tmp)
			, -1);
		free(tmp);
		return (0);
	}
	return (0);
}

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
