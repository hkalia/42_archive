/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:54 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/23 11:38:15 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <ft_custom.h>
#include <stdlib.h>

int8_t	ft_printf_u(t_arr *ret, const char **fmt,
					va_list *ap, t_ft_printf *state)
{
	char				*new;
	uintmax_t			tmp;

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
	FT_GRD1(!(new = ft_itoa_base(tmp, 10, "0123456789"))
			, free(ret->arr), -1);
	FT_GRD2(!ft_arrinsertat(ret, ret->arr_len, new, ft_strlen(new)), free(new)
			, free(ret->arr), -1);
	free(new);
	++*fmt;
	return (1);
}
