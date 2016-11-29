/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:10 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/28 16:03:30 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <ft_stdlib.h>
#include <wchar.h>

static int8_t	ft_printf_c_l(va_list *ap, t_arr *new)
{
	FT_GRD(ft_wctomb((char *)new->arr, va_arg(*ap, wint_t)) == -1, -1);
	if ((new->len = ft_strlen((char *)new->arr)) == 0)
		new->len = 1;
	return (1);
}

int8_t			ft_printf_c(t_arr *ret, const char **fmt
							, va_list *ap, t_ft_printf *state)
{
	unsigned char	tmp;
	t_arr			new;

	FT_GRD1(state->flg_plus || state->flg_hash || state->flg_zero
			|| !(state->int_len_mod == 0 || state->int_len_mod == 3)
			, free(ret->arr), -1);
	ft_bzero(&new, sizeof(t_arr));
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
	FT_GRD2(!width_handler_cs(state, &new), free(new.arr), free(ret->arr), -1);
	FT_GRD2(!ft_arrinsertarrat(ret, ret->len, &new), free(new.arr)
			, free(ret->arr), -1);
	free(new.arr);
	++*fmt;
	return (1);
}
