/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrinsertat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 12:00:58 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/21 15:04:24 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_arr.h>

static int8_t	case2(t_arr *dst, size_t i, const uint8_t *src_cpy
						, size_t src_len)
{
	t_arr	tmp;
	size_t	j;

	FT_GRD(!ft_arrinit(&tmp, dst->arr_len - i), 0);
	j = i;
	while (j < dst->arr_len)
		tmp.arr[tmp.arr_len++] = dst->arr[j++];
	j = 0;
	while (j < src_len)
		dst->arr[i++] = src_cpy[j++];
	j = 0;
	while (j < tmp.arr_len)
		dst->arr[i++] = tmp.arr[j++];
	dst->arr_len = i;
	ft_arrreset_f(&tmp);
	return (1);
}

static int8_t	case1(t_arr *dst, size_t i, const uint8_t *src_cpy
						, size_t src_len)
{
	t_arr	tmp;
	size_t	j;
	size_t	k;

	if (dst->arr_sze < i + src_len)
	{
		FT_GRD(!ft_arrinit(&tmp, i + src_len), 0);
	}
	else
		FT_GRD(!ft_arrinit(&tmp, dst->arr_len + src_len), 0);
	j = 0;
	while (j < dst->arr_len && j < i)
		tmp.arr[tmp.arr_len++] = dst->arr[j++];
	while (tmp.arr_len < i)
		++tmp.arr_len;
	k = 0;
	while (k < src_len)
		tmp.arr[tmp.arr_len++] = src_cpy[k++];
	while (j < dst->arr_len)
		tmp.arr[tmp.arr_len++] = dst->arr[j++];
	ft_arrreset_f(dst);
	FT_ARR_INIT2(dst, tmp.arr_sze, tmp.arr_len, tmp.arr);
	return (1);
}

static int8_t	case0(t_arr *dst, size_t i, const uint8_t *src_cpy
						, size_t src_len)
{
	size_t	j;

	FT_GRD(!ft_arrinit(dst, i + src_len), 0);
	dst->arr_len = i;
	j = 0;
	while (j < src_len)
		dst->arr[dst->arr_len++] = src_cpy[j++];
	return (1);
}

int8_t			ft_arrinsertat(t_arr *dst, size_t i, const void *src
								, size_t src_len)
{
	const uint8_t	*src_cpy;
	size_t			j;

	FT_GRD(!dst, 0);
	FT_GRD(!src || src_len == 0, 1);
	src_cpy = src;
	if (dst->arr_sze == 0 || dst->arr == 0)
		return (case0(dst, i, src_cpy, src_len));
	if (dst->arr_sze - dst->arr_len < src_len
		|| dst->arr_sze < i + src_len)
		return (case1(dst, i, src_cpy, src_len));
	if (i < dst->arr_len)
		return (case2(dst, i, src_cpy, src_len));
	j = 0;
	while (j < src_len)
		dst->arr[i++] = src_cpy[j++];
	dst->arr_len = i;
	return (1);
}