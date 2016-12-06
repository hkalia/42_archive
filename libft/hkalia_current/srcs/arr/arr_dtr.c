/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_dtr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:04:56 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/06 12:15:36 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <stdlib.h>
#include <ft_string.h>

void	arr_dtr(t_arr *src)
{
	size_t	i;

	if (src->cap > 0)
	{
		if (src->inf.dtr)
		{
			i = 0;
			while (i < src->len)
			{
				src->inf.dtr(src->arr + (src->inf.elm * i));
				++i;
			}
		}
		free(src->arr);
	}
	ft_memset(src, 0, sizeof(t_arr));
}
