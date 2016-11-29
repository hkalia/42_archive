/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:02:18 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/21 11:39:49 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_arr.h>
#include <ft_stdlib.h>

int8_t	ft_arrinit(t_arr *src, size_t sze)
{
	FT_GRD(!src, 0);
	src->sze = sze;
	FT_GRD1(!(src->arr = ft_calloc(src->sze, sizeof(uint8_t)))
			, ft_arrreset(src), 0);
	src->len = 0;
	return (1);
}
