/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:41 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/23 11:34:21 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <ft_custom.h>
#include <stdlib.h>

int8_t	ft_printf_d(t_arr *ret, const char **fmt,
					va_list *ap, t_ft_printf *state)
{
	char				*new;
	intmax_t			tmp;

	tmp = 0;
	if (state->int_len_mod == 0)
		tmp = va_arg(*ap, int);
	else if (state->int_len_mod == 1)
		tmp = (signed char)va_arg(*ap, int);
	else if (state->int_len_mod == 2)
		tmp = (short)va_arg(*ap, int);
	else if (state->int_len_mod == 3)
		tmp = va_arg(*ap, long);
	else if (state->int_len_mod == 4)
		tmp = va_arg(*ap, long long);
	else if (state->int_len_mod == 5)
		tmp = va_arg(*ap, intmax_t);
	else if (state->int_len_mod == 6)
		tmp = va_arg(*ap, ssize_t);
	FT_GRD1(!(new = ft_itoa(tmp)), free(ret->arr), -1);
	FT_GRD2(!ft_arrinsertat(ret, ret->arr_len, new, ft_strlen(new)), free(new)
			, free(ret->arr), -1);
	free(new);
	++*fmt;
	return (1);
}
