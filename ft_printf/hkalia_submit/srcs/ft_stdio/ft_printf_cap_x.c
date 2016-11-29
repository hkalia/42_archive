/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cap_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:38 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/28 16:03:13 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <ft_custom.h>
#include <stdlib.h>

int8_t	ft_printf_cap_x(t_arr *ret, const char **fmt,
						va_list *ap, t_ft_printf *state)
{
	t_arr		new;
	uintmax_t	tmp;

	ft_bzero(&new, sizeof(t_arr));
	tmp = get_input(ap, state);
	FT_GRD1(!(new.arr = (uint8_t *)ft_itoa_base(tmp, 16, "0123456789ABCDEF"))
			, free(ret->arr), -1);
	new.len = ft_strlen((char *)new.arr);
	new.sze = new.len + 1;
	FT_GRD2(!ft_arrinsertarrat(ret, ret->len, &new), free(new.arr)
			, free(ret->arr), -1);
	free(new.arr);
	++*fmt;
	return (1);
}
