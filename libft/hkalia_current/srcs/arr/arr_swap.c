/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 12:45:27 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/21 14:40:03 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>

void	arr_swap(t_arr *src, size_t i, size_t j)
{
	uint8_t	tmp;
	uint8_t	*a;
	uint8_t	*b;
	size_t	cpyidx;

	if (i > src->len || j > src->len || i == j)
		return ;
	a = ARR_INDEX(src, i);
	b = ARR_INDEX(src, j);
	cpyidx = 0;
	while (cpyidx < src->elm)
	{
		tmp = a[cpyidx];
		a[cpyidx] = b[cpyidx];
		b[cpyidx] = tmp;
		cpyidx++;
	}
}
