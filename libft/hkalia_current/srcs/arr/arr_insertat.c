/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_insertat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:08:42 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/14 17:04:18 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <ft_stdlib.h>
#include <ft_string.h>

int8_t	arr_insertat(t_arr *dst, size_t i, void *src, size_t src_len)
{
	size_t	j;
	uint8_t	*tmp;

	GRD(dst == 0, -1);
	GRD(src == 0 || src_len == 0, 0);
	j = i > dst->cap ? (i - dst->cap) + src_len : src_len;
	GRD(arr_reserve(dst, j) == -1, -1);
	if (dst->len > i)
	{
		GRD((tmp = ft_calloc(dst->len - i, sizeof(uint8_t))) == 0, -1);
		ft_memcpy(tmp, &dst->arr[i], dst->len - i);
		ft_memcpy(&dst->arr[i], src, src_len);
		ft_memcpy(&dst->arr[i + src_len], tmp, dst->len - i);
	}
	else
		ft_memcpy(&dst->arr[i], src, src_len);
	dst->len += i + src_len;
	return (0);
}
