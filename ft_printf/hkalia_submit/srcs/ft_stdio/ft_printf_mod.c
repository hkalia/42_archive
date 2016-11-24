/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:40:01 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/23 11:28:02 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <stdlib.h>

int8_t	ft_printf_mod(t_arr *ret, const char **fmt,
						va_list *ap, t_ft_printf *state)
{
	(void)ap;
	(void)state;
	FT_GRD1(!ft_arrinsertat(ret, ret->arr_len, "%", 1), free(ret->arr), -1);
	++*fmt;
	return (1);
}
