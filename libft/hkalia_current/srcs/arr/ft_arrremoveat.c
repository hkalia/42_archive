/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrremoveat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 14:35:14 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/21 17:10:24 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_arr.h>

int8_t	ft_arrremoveat(t_arr *src, size_t i, size_t size)
{
	size_t	j;

	FT_GRD(!src, 0);
	FT_GRD(src->sze == 0 || src->len == 0 || src->arr == 0
			|| i + size > src->sze || i > src->len, 0);
	FT_GRD1(i + size >= src->len, src->len = i, 1);
	j = 0;
	while (j < size && i + size < src->len)
	{
		src->arr[i] = src->arr[i + size];
		++i;
		++j;
	}
	while (i + size < src->len)
	{
		src->arr[i] = src->arr[i + size];
		++i;
	}
	src->len = i;
	return (1);
}
