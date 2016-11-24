/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 14:41:42 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/21 11:36:30 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_arr.h>

int8_t	ft_arrdup(t_arr *dst, const t_arr *src)
{
	size_t	i;

	FT_GRD(!dst || !src, 0);
	FT_GRD(src->arr_sze == 0 || src->arr == 0, 0);
	FT_GRD(!ft_arrinit(dst, src->arr_sze), 0);
	i = 0;
	while (i < src->arr_len)
	{
		dst->arr[i] = src->arr[i];
		++i;
	}
	dst->arr_len = src->arr_len;
	return (1);
}
