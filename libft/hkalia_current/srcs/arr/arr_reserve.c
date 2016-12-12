/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_reserve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:17:14 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/12 12:31:19 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <mem.h>

int8_t	arr_reserve(t_arr *src, size_t sze)
{
	GRD(src == 0, -1);
	if (src->len + sze > src->cap)
	{
		while (src->len + sze > src->cap)
			src->cap = 2 * src->cap;
		GRD((src->arr = ft_reallocf(src->arr, src->len
			, src->cap * src->inf.elm)) == 0, -1);
	}
	return (0);
}
