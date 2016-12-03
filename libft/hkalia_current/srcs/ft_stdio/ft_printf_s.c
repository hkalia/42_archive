/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:51 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/28 16:04:08 by hkalia           ###   ########.fr       */
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

static int8_t	null_handler(t_arr *ret, const char **fmt)
{
	FT_GRD1(!ft_arrinsertat(ret, ret->len, "(null)", 6)
			, free(ret->arr), -1);
	++*fmt;
	return (1);
}

int8_t			ft_printf_s(t_arr *ret, const char **fmt,
						va_list *ap, t_ft_printf *state)
{
	t_arr	new;
	char	*tmp;

	ft_bzero(&new, sizeof(t_arr));
	if (state->int_len_mod == 3)
	{
		FT_GRD1(ft_printf_s_l(ap, &new) == -1, free(ret->arr), -1);
	}
	else
	{
		if ((tmp = va_arg(*ap, char *)) == 0)
			return (null_handler(ret, fmt));
		FT_GRD1(!ft_arrinsertat(&new, 0, tmp, ft_strlen(tmp)), free(ret->arr)
				, -1);
	}
	if (state->flg_dot && new.len > (size_t)state->int_dot)
		FT_GRD2(!ft_arrremoveat(&new, (size_t)state->int_dot, new.len
				- state->int_dot), free(new.arr), free(ret->arr), -1);
	FT_GRD2(!width_handler_cs(state, &new), free(new.arr), free(ret->arr), -1);
	FT_GRD2(!ft_arrinsertarrat(ret, ret->len, &new), free(new.arr)
			, free(ret->arr), -1);
	free(new.arr);
	++*fmt;
	return (1);
}
