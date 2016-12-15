/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:41 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/15 15:09:50 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <nbr.h>
#include <sys/types.h>
#include <stdlib.h>

int8_t			flg_handler_d(t_ft_printf *state, t_arr *new)
{
	bool	flg_neg;

	if (!(flg_neg = new->arr[0] == '-' ? 1 : 0)
		&& (state->flg_plus || state->flg_space))
		GRD(arr_insertat(new, 0, state->flg_plus ? "+" : " ", 1) == -1, 0);
	return (1);
}

static intmax_t	get_signed_input(va_list *ap, t_ft_printf *state)
{
	if (state->int_len_mod == 0)
		return (va_arg(*ap, int));
	else if (state->int_len_mod == 1)
		return ((signed char)va_arg(*ap, int));
	else if (state->int_len_mod == 2)
		return ((short)va_arg(*ap, int));
	else if (state->int_len_mod == 3)
		return (va_arg(*ap, long));
	else if (state->int_len_mod == 4)
		return (va_arg(*ap, long long));
	else if (state->int_len_mod == 5)
		return (va_arg(*ap, intmax_t));
	else if (state->int_len_mod == 6)
		return (va_arg(*ap, ssize_t));
	else
		return (0);
}

int8_t			ft_printf_d(t_arr *ret, const char **fmt
							, va_list *ap, t_ft_printf *state)
{
	t_arr		new;
	intmax_t	tmp;

	GRD1(state->flg_hash, free(ret->arr), -1);
	ft_bzero(&new, sizeof(t_arr));
	tmp = get_signed_input(ap, state);
	GRD1((new.arr = (uint8_t *)ft_itoa(tmp)) == 0, free(ret->arr), -1);
	new.len = ft_strlen((char *)new.arr);
	new.cap = new.len + 1;
	GRD2(flg_handler_d(state, &new) == 0, free(new.arr), free(ret->arr), -1);
	GRD2(arr_insertat(ret, ret->len, new.arr, new.len) == -1, free(new.arr)
			, free(ret->arr), -1);
	free(new.arr);
	++*fmt;
	return (1);
}
