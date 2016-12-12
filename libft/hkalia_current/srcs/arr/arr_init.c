/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:05:21 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/12 13:56:01 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <ft_string.h>
#include <ft_stdlib.h>

int8_t	arr_init(t_arr *src, size_t elt, size_t cap)
{
	GRD(src == 0 || elt == 0 || cap == 0, -1);
	ft_bzero(src, sizeof(t_arr));
	GRD(!(src->arr = ft_calloc(cap, elt)), -1);
	src->elt = elt;
	src->cap = cap;
	return (0);
}
