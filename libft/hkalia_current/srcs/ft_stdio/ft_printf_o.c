/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:47 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/18 16:22:39 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <nbr.h>
#include <stdlib.h>

uintmax_t	get_input(t_ft_printf *s)
{
	if (s->int_len_mod == 0)
		return (va_arg(*s->ap, unsigned int));
	else if (s->int_len_mod == 1)
		return ((unsigned char)va_arg(*s->ap, unsigned int));
	else if (s->int_len_mod == 2)
		return ((unsigned short)va_arg(*s->ap, unsigned int));
	else if (s->int_len_mod == 3)
		return (va_arg(*s->ap, unsigned long));
	else if (s->int_len_mod == 4)
		return (va_arg(*s->ap, unsigned long long));
	else if (s->int_len_mod == 5)
		return (va_arg(*s->ap, uintmax_t));
	else if (s->int_len_mod == 6)
		return (va_arg(*s->ap, size_t));
	else
		return (0);
}

int8_t		ft_printf_o(t_ft_printf *s)
{
	uintmax_t	tmp;

	tmp = get_input(s);
	GRD1((s->new.arr = (uint8_t *)ft_itoa_base(tmp, 8, "01234567")) == 0
			, free(s->ret.arr), -1);
	s->new.len = ft_strlen((char *)s->new.arr);
	s->new.cap = s->new.len + 1;
	GRD2(arr_insertat(&s->ret, s->ret.len, s->new.arr, s->new.len) == -1
		, free(s->new.arr), free(s->ret.arr), -1);
	arr_dtr(&s->new);
	++s->fmt;
	return (1);
}
