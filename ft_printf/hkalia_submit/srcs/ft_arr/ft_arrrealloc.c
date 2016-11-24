/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:01:54 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/21 16:20:52 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_arr.h>

int8_t	ft_arrrealloc(t_arr *src, size_t arr_sze)
{
	t_arr	tmp;
	size_t	j;

	FT_GRD(!src, 0);
	FT_GRD(!ft_arrinit(&tmp, arr_sze), 0);
	j = 0;
	while (j < src->arr_sze)
		tmp.arr[tmp.arr_len++] = src->arr[j++];
	ft_arrreset_f(src);
	FT_ARR_INIT2(src, tmp.arr_sze, tmp.arr_len, tmp.arr);
	return (1);
}
