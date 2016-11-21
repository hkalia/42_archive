/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:02:18 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/20 14:31:39 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_arr.h>
#include <ft_stdlib.h>

int8_t	ft_arrinit(t_arr *src, size_t arr_sze)
{
	FT_ARR_GRD(!src, 0, 0);
	src->arr_sze = arr_sze;
	FT_ARR_GRD(!(src->arr = ft_calloc(src->arr_sze, sizeof(uint8_t))), src, 0);
	src->arr_len = 0;
	return (1);
}
