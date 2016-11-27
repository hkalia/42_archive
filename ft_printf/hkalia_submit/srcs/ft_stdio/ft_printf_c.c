/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:10 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/26 17:28:53 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <ft_stdlib.h>
#include <wchar.h>

static int8_t	ft_printf_c_l(va_list *ap, t_arr *new)
{
	FT_GRD(ft_wctomb((char *)new->arr, va_arg(*ap, wint_t)) == -1, -1);
	new->arr_len = ft_strlen((char *)new->arr) ?: 1;
	return (1);
}

int8_t			ft_printf_c(t_arr *ret, const char **fmt
							, va_list *ap, t_ft_printf *state)
{
	unsigned char	tmp;
	t_arr			new;

	FT_GRD1(state->flag_plus || state->flag_hash || state->flag_zero
		|| !(state->int_len_mod == 0 || state->int_len_mod == 3)
		, free(ret->arr), -1);
	new = (t_arr){0, 0, 0};
	FT_GRD1(!ft_arrinit(&new, 5), free(ret->arr), -1);
	if (state->int_len_mod == 3)
	{
		FT_GRD2(ft_printf_c_l(ap, &new) == -1, free(new.arr), free(ret->arr)
				, -1);
	}
	else
	{
		tmp = (unsigned char)va_arg(*ap, int);
		FT_GRD2(!ft_arrinsertat(&new, 0, &tmp, 1), free(new.arr), free(ret->arr)
				, -1);
	}
	FT_GRD2(!width_handler(state, &new), free(new.arr), free(ret->arr), -1);
	FT_GRD2(!ft_arrinsertarrat(ret, ret->arr_len, &new), free(new.arr)
			, free(ret->arr), -1);
	free(new.arr);
	++*fmt;
	return (1);
}
