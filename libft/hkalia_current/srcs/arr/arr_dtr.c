/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_dtr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:04:56 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/19 13:03:21 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <stdlib.h>
#include <ft_string.h>

void	arr_dtr(t_arr *src)
{
	if (src == 0)
		return ;
	if (src->cap > 0)
		free(src->arr);
	ft_bzero(src, sizeof(t_arr));
}
