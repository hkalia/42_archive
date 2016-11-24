/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:49 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/23 11:27:53 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <ft_string.h>

int8_t	ft_printf_p(t_arr *ret, const char **fmt,
					va_list *ap, t_ft_printf *state)
{
	(void)ap;
	(void)state;
	FT_GRD1(!ft_arrinsertat(ret, ret->arr_len, "p", 1), free(ret->arr), -1);
	++*fmt;
	return (1);
}
