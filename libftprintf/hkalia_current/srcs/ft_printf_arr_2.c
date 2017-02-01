/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arr_insert.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:08:42 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/30 14:40:36 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int8_t	ft_printf_arr_insert(t_ft_printf_arr *dst, size_t idx, const void *src)
{
	GRD(dst == 0, -1);
	GRD(dst->cap == 0, -1);
	if (idx > dst->len)
		GRD(ft_printf_arr_resize(dst, idx) == -1, -1);
	GRD(ft_printf_arr_reserve(dst, 1) == -1, -1);
	if (idx < dst->len)
		ft_printf_memmove(&dst->ptr[idx + 1], &dst->ptr[idx], dst->len - idx);
	ft_printf_memcpy(&dst->ptr[idx], src, 1);
	++dst->len;
	return (0);
}

int8_t	ft_printf_arr_insertm(t_ft_printf_arr *dst, size_t idx, const void *src
								, size_t src_len)
{
	GRD(dst == 0, -1);
	GRD(dst->cap == 0, -1);
	GRD(src_len == 0, 0);
	if (idx > dst->len)
		GRD(ft_printf_arr_resize(dst, idx) == -1, -1);
	GRD(ft_printf_arr_reserve(dst, src_len) == -1, -1);
	if (idx < dst->len)
		ft_printf_memmove(&dst->ptr[idx + src_len], &dst->ptr[idx]
								, dst->len - idx);
	ft_printf_memcpy(&dst->ptr[idx], src, src_len);
	dst->len += src_len;
	return (0);
}

int8_t	ft_printf_arr_insertarr(t_ft_printf_arr *dst, size_t idx
								, t_ft_printf_arr *src)
{
	GRD(dst == 0, -1);
	GRD(dst->cap == 0, -1);
	GRD(src->len == 0, 0);
	if (idx > dst->len)
		GRD(ft_printf_arr_resize(dst, idx) == -1, -1);
	GRD(ft_printf_arr_reserve(dst, src->len) == -1, -1);
	if (idx < dst->len)
		ft_printf_memmove(&dst->ptr[idx + src->len], &dst->ptr[idx]
							, dst->len - idx);
	ft_printf_memcpy(&dst->ptr[idx], src->ptr, src->len);
	dst->len += src->len;
	return (0);
}

int8_t	ft_printf_arr_removem(t_ft_printf_arr *src, size_t idx, size_t len)
{
	GRD(src == 0, -1);
	GRD(src->cap == 0 || idx + len > src->len, -1);
	ft_printf_memmove(&src->ptr[idx], &src->ptr[idx + len]
						, src->len - (idx + len));
	src->len -= len;
	return (0);
}
