/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:10 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/23 13:04:59 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <ft_stdlib.h>
#include <wchar.h>

static int8_t	ft_printf_c_l(va_list *ap, char **new)
{
	wint_t	tmp;

	tmp = va_arg(*ap, wint_t);
	FT_GRD(!(*new = ft_calloc(5, sizeof(char))), -1);
	FT_GRD1(ft_wctomb(*new, tmp) == -1, free(*new), -1);
	return (1);
}

int8_t			ft_printf_c(t_arr *ret, const char **fmt,
					va_list *ap, t_ft_printf *state)
{
	unsigned char	tmp;
	char			*new;

	FT_GRD1(state->flag_plus || state->flag_space
		|| state->flag_hash || state->flag_zero
		|| state->flag_dot != 0
		|| !(state->int_len_mod == 0 || state->int_len_mod == 3)
		, free(ret->arr), -1);
	if (state->int_len_mod == 3)
	{
		FT_GRD1(ft_printf_c_l(ap, &new) == -1, free(ret->arr), -1);
	}
	else
	{
		FT_GRD1(!(new = ft_calloc(2, sizeof(char))), free(ret->arr), -1);
		tmp = (unsigned char)va_arg(*ap, int);
		new[0] = tmp;
	}
	FT_GRD2(!ft_arrinsertat(ret, ret->arr_len, new, ft_strlen(new) ?: 1)
			, free(new), free(ret->arr), -1);
	free(new);
	++*fmt;
	return (1);
}
