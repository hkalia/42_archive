/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:05:21 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/13 13:12:00 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <ft_string.h>
#include <ft_stdlib.h>

int8_t	arr_init(t_arr *src, size_t cap)
{
	GRD(src == 0, -1);
	ft_bzero(src, sizeof(t_arr));
	if (cap != 0)
	{
		GRD(!(src->arr = ft_calloc(cap, 1)), -1);
		src->cap = cap;
	}
	return (0);
}
