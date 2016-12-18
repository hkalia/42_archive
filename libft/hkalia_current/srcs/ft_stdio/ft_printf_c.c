/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:10 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/17 16:57:40 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <ft_stdlib.h>
#include <stdlib.h>
#include <wchar.h>

static int8_t	ft_printf_c_l(va_list *ap, t_arr *new)
{
	size_t	i;

	GRD((i = ft_wctomb((char *)new->arr, va_arg(*ap, wint_t))) == -1, -1);
	if ((new->len = i) == 0)
		new->len = 1;
	return (0);
}

int8_t			ft_printf_c(t_arr *ret, const char **fmt
							, va_list *ap, t_ft_printf *state)
{
	unsigned char	tmp;
	t_arr			new;

	GRD1(state->flg_hash || !(state->int_len_mod == 0
		|| state->int_len_mod == 3), free(ret->arr), -1);
	GRD1(arr_init(&new, 5) == -1, free(ret->arr), -1);
	if (state->int_len_mod == 3)
		GRD2(ft_printf_c_l(ap, &new) == -1, free(new.arr), free(ret->arr), -1);
	else
	{
		tmp = (unsigned char)va_arg(*ap, int);
		GRD2(arr_insertat(&new, 0, &tmp, 1) == -1, free(new.arr), free(ret->arr)
				, -1);
	}
	GRD2(width_handler_csp(state, &new) == -1, free(new.arr), free(ret->arr)
		, -1);
	GRD2(arr_insertat(ret, ret->len, new.arr, new.len) == -1, free(new.arr)
			, free(ret->arr), -1);
	free(new.arr);
	++*fmt;
	return (1);
}
