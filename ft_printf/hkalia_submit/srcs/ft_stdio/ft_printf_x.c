/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:56 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/26 17:43:34 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <ft_custom.h>
#include <stdlib.h>

int8_t	ft_printf_x(t_arr *ret, const char **fmt
					, va_list *ap, t_ft_printf *state)
{
	t_arr		new;
	uintmax_t	tmp;

	new = (t_arr){0, 0, 0};
	tmp = get_input(ap, state);
	FT_GRD1(!(new.arr = (uint8_t *)ft_itoa_base(tmp, 16, "0123456789abcdef"))
			, free(ret->arr), -1);
	new.arr_len = ft_strlen((char *)new.arr);
	new.arr_sze = new.arr_len + 1;
	if (tmp == 0 && state->flag_dot && state->int_dot == 0)
	{
		FT_GRD2(!ft_arrremoveat(&new, 0, new.arr_len), free(new.arr)
				, free(ret->arr), -1);
	}
	else if (state->flag_hash && state->flag_zero && tmp != 0)
		FT_GRD2(!ft_arrinsertat(&new, 0, "0x", 2), free(new.arr), free(ret->arr)
				, -1);
	FT_GRD2(!width_handler(state, &new), free(new.arr), free(ret->arr), -1);
	FT_GRD2(!ft_arrinsertarrat(ret, ret->arr_len, &new), free(new.arr)
			, free(ret->arr), -1);
	free(new.arr);
	++*fmt;
	return (1);
}
