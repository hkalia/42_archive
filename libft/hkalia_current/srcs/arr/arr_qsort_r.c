/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_qsort_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:04:50 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/21 14:43:46 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <stdio.h>

#define SWAP(a, b) tmp = a; a = b; b = tmp;

static size_t	median(t_arr *src, size_t len, void *thunk
						, int (*cmp)(const void *, const void *, size_t
									, void *))
{
	size_t i;
	size_t j;
	size_t k;
	size_t tmp;

	i = 0;
	j = len / 2;
	k = len - 1;
	tmp = 0;
	if (cmp(ARR_INDEX(src, k), ARR_INDEX(src, i), src->elm, thunk) < 0)
	{
		SWAP(k, i);
	}
	if (cmp(ARR_INDEX(src, j), ARR_INDEX(src, i), src->elm, thunk) < 0)
	{
		SWAP(j, i);
	}
	if (cmp(ARR_INDEX(src, k), ARR_INDEX(src, j), src->elm, thunk) < 0)
	{
		SWAP(j, k);
	}
	return (j);
}

static void		recursor(t_arr *src, size_t len, void *thunk
						, int (*cmp)(const void *, const void *, size_t
									, void *))
{
	size_t	i;
	size_t	pivot_idx;

	if (len <= 1)
		return ;
	arr_swap(src, 0, median(src, len, thunk, cmp));
	i = 1;
	pivot_idx = 0;
	while (i < len)
	{
		if (cmp(ARR_INDEX(src, i), ARR_INDEX(src, 0), src->elm, thunk) <= 0)
			arr_swap(src, i, ++pivot_idx);
		++i;
	}
	arr_swap(src, 0, pivot_idx);
	recursor(src, pivot_idx, thunk, cmp);
	*(char **)&src->arr += src->elm * (pivot_idx + 1);
	recursor(src, len - pivot_idx - 1, thunk, cmp);
	*(char **)&src->arr -= src->elm * (pivot_idx + 1);
}

void			arr_qsort_r(t_arr *src, void *thunk, int (*cmp)(const void *
						, const void *, size_t, void *))
{
	recursor(src, src->len, thunk, cmp);
}
