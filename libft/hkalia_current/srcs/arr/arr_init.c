/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:05:21 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/06 12:04:03 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <ft_string.h>
#include <ft_stdlib.h>

int8_t	arr_init(t_arr *src, t_arr_inf *src_inf)
{
	ft_memset(src, 0, sizeof(t_arr));
	src->inf = *src_inf;
	src->cap = ARR_INIT_SZE;
	GRD(!(src->arr = ft_calloc(src->cap, src->inf.elm)), -1);
	return (0);
}
