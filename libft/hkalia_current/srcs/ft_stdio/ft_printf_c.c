/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:10 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/15 15:14:08 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <ft_stdlib.h>
#include <stdlib.h>
#include <wchar.h>

static int8_t	ft_printf_c_l(va_list *ap, t_arr *new)
{
	GRD(ft_wctomb((char *)new->arr, va_arg(*ap, wint_t)) == -1, -1);
	if ((new->len = ft_strlen((char *)new->arr)) == 0)
		new->len = 1;
	return (1);
}

int8_t			ft_printf_c(t_arr *ret, const char **fmt
							, va_list *ap, t_ft_printf *state)
{
	unsigned char	tmp;
	t_arr			new;

	GRD1(state->flg_plus || state->flg_hash || state->flg_zero
			|| !(state->int_len_mod == 0 || state->int_len_mod == 3)
			, free(ret->arr), -1);
	ft_bzero(&new, sizeof(t_arr));
	GRD1(arr_init(&new, 5) == -1, free(ret->arr), -1);
	if (state->int_len_mod == 3)
	{
		GRD2(ft_printf_c_l(ap, &new) == -1, free(new.arr), free(ret->arr)
				, -1);
	}
	else
	{
		tmp = (unsigned char)va_arg(*ap, int);
		GRD2(arr_insertat(&new, 0, &tmp, 1) == -1, free(new.arr), free(ret->arr)
				, -1);
	}
	GRD2(width_handler_cs(state, &new) == 0, free(new.arr), free(ret->arr), -1);
	GRD2(arr_insertat(ret, ret->len, new.arr, new.len) == -1, free(new.arr)
			, free(ret->arr), -1);
	free(new.arr);
	++*fmt;
	return (1);
}
