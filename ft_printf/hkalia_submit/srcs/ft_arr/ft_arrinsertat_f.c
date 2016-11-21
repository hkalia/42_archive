/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrinsertat_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 13:05:48 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/20 16:52:37 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_arr.h>
#include <stdlib.h>

#define FT_ARR_GRD2(a, b, c) if (a) {free(b); return(c);}

static int8_t	case2(t_arr *dst, size_t i, uint8_t *src_cpy
						, size_t src_len)
{
	t_arr	tmp;
	size_t	j;

	FT_ARR_GRD2(!ft_arrinit(&tmp, dst->arr_len - i), src_cpy, 0);
	j = i;
	while (j < dst->arr_len)
		tmp.arr[tmp.arr_len++] = dst->arr[j++];
	j = 0;
	while (j < src_len)
		dst->arr[i++] = src_cpy[j++];
	j = 0;
	while (j < tmp.arr_len)
		dst->arr[i++] = tmp.arr[j++];
	ft_arrreset(&tmp);
	free(src_cpy);
	return (1);
}

static int8_t	case1(t_arr *dst, size_t i, uint8_t *src_cpy
						, size_t src_len)
{
	t_arr	tmp;
	size_t	j;
	size_t	k;

	if (dst->arr_sze < i + src_len)
	{
		FT_ARR_GRD2(!ft_arrinit(&tmp, i + src_len), src_cpy, 0);
	}
	else
		FT_ARR_GRD2(!ft_arrinit(&tmp, dst->arr_len + src_len), src_cpy, 0);
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
	ft_arrreset(dst);
	FT_ARR_INIT(dst, tmp.arr_sze, tmp.arr_len, tmp.arr);
	free(src_cpy);
	return (1);
}

static int8_t	case0(t_arr *dst, size_t i, uint8_t *src_cpy
						, size_t src_len)
{
	size_t	j;

	FT_ARR_GRD2(!ft_arrinit(dst, i + src_len), src_cpy, 0);
	dst->arr_len = i;
	j = 0;
	while (j < src_len)
		dst->arr[dst->arr_len++] = src_cpy[j++];
	free(src_cpy);
	return (1);
}

int8_t			ft_arrinsertat_f(t_arr *dst, size_t i, void *src
								, size_t src_len)
{
	uint8_t	*src_cpy;
	size_t	j;

	FT_ARR_GRD2(!dst, 0, 0);
	FT_ARR_GRD2(!src || src_len == 0, src, 1);
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
	free(src_cpy);
	return (1);
}
