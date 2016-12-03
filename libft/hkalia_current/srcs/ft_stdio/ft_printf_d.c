/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:41 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/28 15:54:50 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <ft_custom.h>
#include <stdlib.h>

int8_t			flg_handler_d(t_ft_printf *state, t_arr *new)
{
	bool	flg_neg;

	if (!(flg_neg = new->arr[0] == '-' ? 1 : 0)
		&& (state->flg_plus || state->flg_space))
		FT_GRD(!ft_arrinsertat(new, 0, state->flg_plus ? "+" : " ", 1), 0);
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

	FT_GRD1(state->flg_hash, free(ret->arr), -1);
	ft_bzero(&new, sizeof(t_arr));
	tmp = get_signed_input(ap, state);
	FT_GRD1(!(new.arr = (uint8_t *)ft_itoa(tmp)), free(ret->arr), -1);
	new.len = ft_strlen((char *)new.arr);
	new.sze = new.len + 1;
	FT_GRD2(!flg_handler_d(state, &new), free(new.arr), free(ret->arr), -1);
	FT_GRD2(!ft_arrinsertarrat(ret, ret->len, &new), free(new.arr)
			, free(ret->arr), -1);
	free(new.arr);
	++*fmt;
	return (1);
}
