/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_push_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:17:14 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/12 13:43:21 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <ft_string.h>

int8_t	arr_push_back(t_arr *dst, void *elm)
{
	GRD(dst == 0, -1);
	GRD(arr_reserve(dst, 1) == -1, -1);
	if (dst->inf.cpy != 0)
		GRD(dst->inf.cpy(dst->arr + dst->inf.elm * dst->len++, elm) == -1, -1);
	else
		ft_memcpy(dst->arr + dst->inf.elm * dst->len++, elm, dst->inf.elm);
	return (0);
}
