/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_insertat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:08:42 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/19 14:39:45 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <ft_string.h>

int8_t	arr_insertat(t_arr *dst, size_t i, const void *src, size_t src_len)
{
	GRD(dst == 0, -1);
	GRD(src == 0 || src_len == 0, 0);
	GRD(arr_reserve(dst
		, i > dst->cap ? (i - dst->cap) + src_len : src_len) == -1, -1);
	if (dst->len > i)
	{
		ft_memmove(ARR_INDEX(dst, i + src_len), ARR_INDEX(dst, i)
					, (dst->len - i) * dst->elm);
		ft_memcpy(ARR_INDEX(dst, i), src, src_len * dst->elm);
		dst->len += src_len;
	}
	else
	{
		ft_memcpy(ARR_INDEX(dst, i), src, src_len * dst->elm);
		dst->len = i + src_len;
	}
	return (0);
}
