/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:40:01 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/15 15:20:18 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <stdlib.h>

int8_t	ft_printf_mod(t_arr *ret, const char **fmt,
						va_list *ap, t_ft_printf *state)
{
	t_arr	new;

	(void)ap;
	(void)state;
	ft_bzero(&new, sizeof(t_arr));
	GRD1(arr_insertat(&new, 0, "%", 1) == -1, free(ret->arr), -1);
	GRD2(width_handler_cs(state, &new) == 0, free(new.arr), free(ret->arr), -1);
	GRD2(arr_insertat(ret, ret->len, new.arr, new.len) == -1, free(new.arr)
			, free(ret->arr), -1);
	free(new.arr);
	++*fmt;
	return (1);
}
