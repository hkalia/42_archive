/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:11:37 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/12 13:35:17 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <ft_string.h>

int8_t	arr_resize(t_arr *src, size_t sze)
{
	size_t	i;

	GRD(src == 0, -1);
	if (src->len > sze)
	{
		if (src->inf.dtr)
		{
			i = sze;
			while (i < src->len)
			{
				src->inf.dtr(src->arr + src->inf.elm * i);
				++i;
			}
		}
	}
	else if (src->len < sze)
	{
		GRD(arr_reserve(src, sze - src->len) == -1, -1);
		if (src->inf.init != 0)
		{
			i = src->len;
			while (i < sze)
			{
				GRD(src->inf.init(src->arr + src->inf.elm * i) == -1, -1);
				++i;
			}
		}
	}
	else
		ft_memset(src->arr + src->inf.elm * src->len, 0
					, src->inf.elm * (sze - src->len));
	src->len = sze;
	return (0);
}
