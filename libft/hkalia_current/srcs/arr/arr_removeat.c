/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_removeat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:21:18 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/19 13:25:24 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <ft_string.h>

int8_t	arr_removeat(t_arr *src, size_t i, size_t len)
{
	GRD(src == 0 || i + len > src->len, -1);
	ft_memmove(ARR_INDEX(src, i), ARR_INDEX(src, i + len)
				, (src->len - len - i) * src->elm);
	src->len -= len;
	return (0);
}
