/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:05:21 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/10 14:43:06 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <ft_string.h>
#include <ft_stdlib.h>

int8_t	arr_init(t_arr *src, t_arr_inf *src_inf, size_t cap)
{
	GRD(src == 0 || cap == 0, -1);
	if (src_inf == 0)
		src_inf = &(t_arr_inf){1, 0, 0, 0};
	ft_bzero(src, sizeof(t_arr));
	src->inf = *src_inf;
	src->cap = cap;
	GRD(!(src->arr = ft_calloc(src->cap, src->inf.elm)), -1);
	return (0);
}
