/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_tostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:45:35 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/14 19:47:45 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>

char	*arr_tostr(t_arr *src)
{
	GRD(src == 0, 0);
	if (src->len != src->cap)
		if (src->arr[src->len] == 0)
			return ((char *)src->arr);
	GRD(arr_insertat(src, src->len, "", 1) == -1, 0);
	--src->len;
	return ((char *)src->arr);
}
