/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_insertat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:08:42 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/13 14:43:27 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <ft_string.h>

int8_t	arr_insertat(t_arr *dst, size_t i, void *src, size_t src_len)
{
	uint8_t	*src_cpy;
	t_arr	tmp;

	GRD(dst == 0, -1);
	GRD(src == 0 || src_len == 0, 0);
	if (i > dst->cap)
		GRD(arr_reserve(dst, (i - dst->cap) + src_len) == -1, -1);
	else
		GRD(arr_reserve(dst, src_len) == -1, -1);
	if (dst->len > i)
	{
		GRD(arr_init(&tmp, dst->len - i) == -1, -1);
		ft_memcpy(tmp.arr, &dst->arr[dst->len], dst->len - i);
	}
	else
		GRD(arr_init(&tmp, 0) == -1, -1);
	ft_memcpy(&dst->arr[i], src, src_len);
	dst->len 
	return (0);
}
