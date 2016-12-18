/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:51 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/17 17:08:03 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <ft_stdlib.h>
#include <stdlib.h>
#include <wchar.h>

static int8_t	null_handler(t_arr *ret, t_ft_printf *state, const char **fmt)
{
	t_arr	new;

	ft_bzero(&new, sizeof(t_arr));
	if (state->int_width > 0)
	{
		GRD2(width_handler_csp(state, &new) == -1, free(new.arr), free(ret->arr)
			, -1);
		GRD2(arr_insertat(ret, ret->len, new.arr, new.len) == -1, free(new.arr)
			, free(ret->arr), -1);
		free(new.arr);
	}
	else
		GRD1(arr_insertat(ret, ret->len, "(null)", 6) == -1
			, free(ret->arr), -1);
	++*fmt;
	return (1);
}

static int8_t	ft_printf_s_l(wchar_t *src, t_arr *new)
{
	char	*new2;
	int		tmp;
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i] != 0)
		++i;
	GRD((new2 = ft_calloc(i, sizeof(wint_t))) == 0, -1);
	i = 0;
	j = 0;
	while (src[i] != 0)
	{
		GRD1((tmp = ft_wctomb(&new2[j], src[i])) == -1, free(new2), -1);
		j += tmp;
		++i;
	}
	GRD1(arr_insertat(new, 0, new2, j) == -1, free(new2), -1);
	free(new2);
	return (0);
}

int8_t			ft_printf_s(t_arr *ret, const char **fmt
							, va_list *ap, t_ft_printf *state)
{
	t_arr	new;
	wchar_t	*tmp;
	char	*tmp1;

	ft_bzero(&new, sizeof(t_arr));
	if (state->int_len_mod == 3)
	{
		GRD((tmp = va_arg(*ap, wchar_t *)) == 0, null_handler(ret, state, fmt));
		GRD1(ft_printf_s_l(tmp, &new) == -1, free(ret->arr), -1);
	}
	else
	{
		GRD((tmp1 = va_arg(*ap, char *)) == 0, null_handler(ret, state, fmt));
		GRD1(arr_insertat(&new, 0, tmp1, ft_strlen(tmp1)) == -1, free(ret->arr)
				, -1);
	}
	if (state->flg_dot && new.len > (size_t)state->int_dot)
		GRD2(arr_removeat(&new, state->int_dot, new.len - state->int_dot) == -1
			, free(new.arr), free(ret->arr), -1);
	GRD2(width_handler_csp(state, &new) == -1, free(new.arr), free(ret->arr)
		, -1);
	GRD2(arr_insertat(ret, ret->len, new.arr, new.len) == -1, free(new.arr)
			, free(ret->arr), -1);
	free(new.arr);
	++*fmt;
	return (1);
}
