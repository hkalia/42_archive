/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_insertat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:08:42 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/14 17:37:13 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <ft_stdlib.h>
#include <ft_string.h>

int8_t	arr_insertat(t_arr *dst, size_t i, void *src, size_t src_len)
{
	size_t	j;

	GRD(dst == 0, -1);
	GRD(src == 0 || src_len == 0, 0);
	j = i > dst->cap ? (i - dst->cap) + src_len : src_len;
	GRD(arr_reserve(dst, j) == -1, -1);
	if (dst->len > i)
	{
		ft_memmove(&dst->arr[i + src_len], &dst->arr[i], dst->len - i);
		ft_memcpy(&dst->arr[i], src, src_len);
	}
	else
		ft_memcpy(&dst->arr[i], src, src_len);
	dst->len += j;
	return (0);
}
