/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 14:35:14 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/19 14:40:16 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_arr.h>

int8_t	ft_arrremove(t_arr **src, size_t i, size_t end)
{
	t_arr	*tmp;

	FT_ARR_GRD(!src, 0, 0);
	FT_ARR_GRD(!*src, 0, 0);
	FT_ARR_GRD((*src)->arr_len < end, 0, 0);
	ft_arrdel(src);
	*src = tmp;
	return (1);
}
