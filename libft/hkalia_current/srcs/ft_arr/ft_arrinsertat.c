/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrinsertat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 12:00:58 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/28 15:47:21 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_arr.h>

static int8_t	case2(t_arr *dst, size_t i, const uint8_t *src_cpy
						, size_t src_len)
{
	t_arr	tmp;
	size_t	j;

	FT_GRD(!ft_arrinit(&tmp, dst->len - i), 0);
	j = i;
	while (j < dst->len)
		tmp.arr[tmp.len++] = dst->arr[j++];
	j = 0;
	while (j < src_len)
		dst->arr[i++] = src_cpy[j++];
	j = 0;
	while (j < tmp.len)
		dst->arr[i++] = tmp.arr[j++];
	dst->len = i;
	ft_arrreset_f(&tmp);
	return (1);
}

static int8_t	case1(t_arr *dst, size_t i, const uint8_t *src_cpy
						, size_t src_len)
{
	t_arr	tmp;
	size_t	j;
	size_t	k;

	if (dst->sze < i + src_len)
	{
		FT_GRD(!ft_arrinit(&tmp, i + src_len), 0);
	}
	else
		FT_GRD(!ft_arrinit(&tmp, dst->len + src_len), 0);
	j = 0;
	while (j < dst->len && j < i)
		tmp.arr[tmp.len++] = dst->arr[j++];
	while (tmp.len < i)
		++tmp.len;
	k = 0;
	while (k < src_len)
		tmp.arr[tmp.len++] = src_cpy[k++];
	while (j < dst->len)
		tmp.arr[tmp.len++] = dst->arr[j++];
	ft_arrreset_f(dst);
	FT_ARR_INIT2(dst, tmp.sze, tmp.len, tmp.arr);
	return (1);
}

static int8_t	case0(t_arr *dst, size_t i, const uint8_t *src_cpy
						, size_t src_len)
{
	size_t	j;

	FT_GRD(!ft_arrinit(dst, i + src_len), 0);
	dst->len = i;
	j = 0;
	while (j < src_len)
		dst->arr[dst->len++] = src_cpy[j++];
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
	if (dst->sze == 0 || dst->arr == 0)
		return (case0(dst, i, src_cpy, src_len));
	if (dst->sze - dst->len < src_len
		|| dst->sze < i + src_len)
		return (case1(dst, i, src_cpy, src_len));
	if (i < dst->len)
		return (case2(dst, i, src_cpy, src_len));
	j = 0;
	while (j < src_len)
		dst->arr[i++] = src_cpy[j++];
	dst->len = i;
	return (1);
}
