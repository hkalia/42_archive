/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_reserve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:01:31 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/19 13:14:28 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <ft_string.h>
#include <stdlib.h>

int8_t	arr_reserve(t_arr *src, size_t sze)
{
	void	*tmp;

	GRD(src == 0, -1);
	if (src->len + sze > src->cap)
	{
		if (src->cap == 0)
			src->cap = sze;
		while (src->len + sze > src->cap)
			src->cap = ARR_GROW_FACTOR * src->cap;
		GRD((tmp = malloc(src->cap * src->elm)) == 0, -1);
		ft_memcpy(tmp, src->arr, src->len * src->elm);
		free(src->arr);
		src->arr = tmp;
	}
	return (0);
}
