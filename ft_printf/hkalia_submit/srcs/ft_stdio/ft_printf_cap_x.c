/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cap_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:38 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/24 16:50:39 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <ft_custom.h>
#include <stdlib.h>

int8_t	ft_printf_cap_x(t_arr *ret, const char **fmt,
						va_list *ap, t_ft_printf *state)
{
	t_arr		new;
	uintmax_t	tmp;

	new = (t_arr){0, 0, 0};
	tmp = 0;
	if (state->int_len_mod == 0)
		tmp = va_arg(*ap, unsigned int);
	else if (state->int_len_mod == 1)
		tmp = (unsigned char)va_arg(*ap, unsigned int);
	else if (state->int_len_mod == 2)
		tmp = (unsigned short)va_arg(*ap, unsigned int);
	else if (state->int_len_mod == 3)
		tmp = va_arg(*ap, unsigned long);
	else if (state->int_len_mod == 4)
		tmp = va_arg(*ap, unsigned long long);
	else if (state->int_len_mod == 5)
		tmp = va_arg(*ap, uintmax_t);
	else if (state->int_len_mod == 6)
		tmp = va_arg(*ap, size_t);
	FT_GRD1(!(new.arr = (uint8_t *)ft_itoa_base(tmp, 16, "0123456789ABCDEF"))
			, free(ret->arr), -1);
	new.arr_len = ft_strlen((char *)new.arr);
	new.arr_sze = new.arr_len + 1;
	FT_GRD2(!width_handler(state, &new), free(new.arr), free(ret->arr), -1);
	FT_GRD2(!ft_arrinsertarrat(ret, ret->arr_len, &new), free(new.arr)
			, free(ret->arr), -1);
	free(new.arr);
	++*fmt;
	return (1);
}
