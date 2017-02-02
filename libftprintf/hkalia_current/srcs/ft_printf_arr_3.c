/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arr_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:08:42 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/01 12:45:54 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int8_t	ft_printf_arr_append(t_ft_printf_arr *dst, const void *src)
{
	GRD(dst == 0, -1);
	GRD(dst->cap == 0, -1);
	GRD(ft_printf_arr_reserve(dst, 1) == -1, -1);
	ft_printf_memcpy(&dst->ptr[dst->len], src, 1);
	++dst->len;
	return (0);
}

int8_t	ft_printf_arr_appendm(t_ft_printf_arr *dst, const void *src
								, size_t src_len)
{
	GRD(dst == 0, -1);
	GRD(dst->cap == 0, -1);
	GRD(src_len == 0, 0);
	GRD(ft_printf_arr_reserve(dst, src_len) == -1, -1);
	ft_printf_memcpy(&dst->ptr[dst->len], src, src_len);
	dst->len += src_len;
	return (0);
}

int8_t	ft_printf_arr_appendarr(t_ft_printf_arr *dst, t_ft_printf_arr *src)
{
	GRD(dst == 0, -1);
	GRD(dst->cap == 0, -1);
	GRD(src->len == 0, 0);
	GRD(ft_printf_arr_reserve(dst, src->len) == -1, -1);
	ft_printf_memcpy(&dst->ptr[dst->len], src->ptr, src->len);
	dst->len += src->len;
	return (0);
}
