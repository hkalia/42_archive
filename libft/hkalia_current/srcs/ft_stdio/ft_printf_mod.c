/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:40:01 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/28 16:32:48 by hkalia           ###   ########.fr       */
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
	FT_GRD1(!ft_arrinsertat(&new, 0, "%", 1), free(ret->arr), -1);
	FT_GRD2(!width_handler_cs(state, &new), free(new.arr), free(ret->arr), -1);
	FT_GRD2(!ft_arrinsertarrat(ret, ret->len, &new), free(new.arr)
			, free(ret->arr), -1);
	free(new.arr);
	++*fmt;
	return (1);
}
