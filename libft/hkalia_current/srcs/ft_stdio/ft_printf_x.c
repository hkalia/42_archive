/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:56 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/15 15:11:07 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <nbr.h>
#include <stdlib.h>

int8_t	ft_printf_x(t_arr *ret, const char **fmt
					, va_list *ap, t_ft_printf *state)
{
	t_arr		new;
	uintmax_t	tmp;

	ft_bzero(&new, sizeof(t_arr));
	tmp = get_input(ap, state);
	GRD1((new.arr = (uint8_t *)ft_itoa_base(tmp, 16, "0123456789abcdef")) == 0
			, free(ret->arr), -1);
	new.len = ft_strlen((char *)new.arr);
	new.cap = new.len + 1;
	if (tmp == 0 && state->flg_dot && state->int_dot == 0)
	{
		GRD2(arr_removeat(&new, 0, new.len) == -1, free(new.arr)
				, free(ret->arr), -1);
	}
	else if (state->flg_hash && tmp != 0)
		GRD2(arr_insertat(&new, 0, "0x", 2) == -1, free(new.arr), free(ret->arr)
				, -1);
	GRD2(arr_insertat(ret, ret->len, new.arr, new.len) == -1, free(new.arr)
			, free(ret->arr), -1);
	free(new.arr);
	++*fmt;
	return (1);
}
