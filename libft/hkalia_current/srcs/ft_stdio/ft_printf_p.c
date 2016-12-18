/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:49 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/17 16:51:24 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <nbr.h>
#include <ft_string.h>
#include <stdlib.h>

static int8_t	dot_handler_p(t_ft_printf *state, t_arr *new)
{
	char	*tmp;
	int		diff;

	if (state->flg_dot == 1)
	{
		if (state->int_dot == 0)
		{
			GRD(arr_removeat(new, 0, new->len) == -1, -1);
			return (0);
		}
		if ((diff = state->int_dot - new->len) > 0)
		{
			GRD((tmp = (char *)malloc(sizeof(char) * diff)) == 0, -1);
			ft_memset(tmp, '0', diff);
			GRD1(arr_insertat(new, 0, tmp, diff) == -1, free(tmp), -1);
			free(tmp);
			return (0);
		}
	}
	return (0);
}

int8_t			ft_printf_p(t_arr *ret, const char **fmt,
							va_list *ap, t_ft_printf *state)
{
	t_arr		new;
	uintmax_t	tmp;

	(void)state;
	ft_bzero(&new, sizeof(t_arr));
	tmp = (uintmax_t)va_arg(*ap, void *);
	GRD1((new.arr = (uint8_t *)ft_itoa_base(tmp, 16, "0123456789abcdef")) == 0
			, free(ret->arr), -1);
	new.len = ft_strlen((char *)new.arr);
	new.cap = new.len + 1;
	GRD2(dot_handler_p(state, &new) == -1, free(new.arr), free(ret->arr), -1);
	GRD2(arr_insertat(&new, 0, "0x", 2) == -1, free(new.arr), free(ret->arr)
		, -1);
	GRD2(width_handler_csp(state, &new) == -1, free(new.arr), free(ret->arr)
		, -1);
	GRD2(arr_insertat(ret, ret->len, new.arr, new.len) == -1, free(new.arr)
			, free(ret->arr), -1);
	free(new.arr);
	++*fmt;
	return (1);
}
