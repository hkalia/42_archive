/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:51 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/15 15:28:36 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <ft_stdlib.h>
#include <stdlib.h>
#include <wchar.h>

int				ft_wcstombs(char **dst, const wchar_t *src)
{
	size_t	i;
	size_t	j;
	int		tmp;

	if (!src || !dst)
		return (-1);
	*dst = 0;
	i = 0;
	while (src[i])
		++i;
	GRD((*dst = ft_calloc(i + 1, sizeof(wint_t))) == 0, -1);
	i = 0;
	j = 0;
	while (src[i])
	{
		GRD2((tmp = ft_wctomb(&((*dst)[j]), src[i])) == -1, free(*dst)
				, *dst = 0, -1);
		j += tmp;
		++i;
	}
	return (j);
}

static int8_t	ft_printf_s_l(va_list *ap, t_arr *new)
{
	char	*tmp;

	tmp = 0;
	GRD(ft_wcstombs(&tmp, va_arg(*ap, wchar_t *)) == -1, -1);
	GRD1(!arr_insertat(new, 0, tmp, ft_strlen(tmp)), free(tmp), -1);
	free(tmp);
	return (1);
}

static int8_t	null_handler(t_arr *ret, const char **fmt)
{
	GRD1(!arr_insertat(ret, ret->len, "(null)", 6)
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
		GRD1(ft_printf_s_l(ap, &new) == -1, free(ret->arr), -1);
	}
	else
	{
		if ((tmp = va_arg(*ap, char *)) == 0)
			return (null_handler(ret, fmt));
		GRD1(!arr_insertat(&new, 0, tmp, ft_strlen(tmp)), free(ret->arr)
				, -1);
	}
	if (state->flg_dot && new.len > (size_t)state->int_dot)
		GRD2(arr_removeat(&new, (size_t)state->int_dot, new.len
				- state->int_dot) == -1, free(new.arr), free(ret->arr), -1);
	GRD2(width_handler_cs(state, &new) == 0, free(new.arr), free(ret->arr), -1);
	GRD2(arr_insertat(ret, ret->len, new.arr, new.len) == -1, free(new.arr)
			, free(ret->arr), -1);
	free(new.arr);
	++*fmt;
	return (1);
}
