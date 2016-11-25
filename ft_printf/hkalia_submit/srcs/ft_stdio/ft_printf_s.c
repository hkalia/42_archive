/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:51 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/24 16:40:59 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <ft_string.h>
#include <wchar.h>

static int8_t	ft_printf_s_l(va_list *ap, t_arr *new)
{
	char	*tmp;

	tmp = 0;
	FT_GRD(ft_wcstombs(&tmp, va_arg(*ap, wchar_t *)) == -1, -1);
	FT_GRD1(!ft_arrinsertat(new, 0, tmp, ft_strlen(tmp)), free(tmp), -1);
	free(tmp);
	return (1);
}

int8_t			ft_printf_s(t_arr *ret, const char **fmt,
						va_list *ap, t_ft_printf *state)
{
	t_arr	new;
	char	*tmp;

	new = (t_arr){0, 0, 0};
	if (state->int_len_mod == 3)
	{
		FT_GRD1(ft_printf_s_l(ap, &new) == -1, free(ret->arr), -1);
	}
	else
	{
		tmp = va_arg(*ap, char *);
		FT_GRD1(!ft_arrinsertat(&new, 0, tmp, ft_strlen(tmp)), free(ret->arr)
				, -1);
	}
	FT_GRD2(!width_handler(state, &new), free(new.arr), free(ret->arr), -1);
	FT_GRD2(!ft_arrinsertarrat(ret, ret->arr_len, &new), free(new.arr)
			, free(ret->arr), -1);
	free(new.arr);
	++*fmt;
	return (1);
}
