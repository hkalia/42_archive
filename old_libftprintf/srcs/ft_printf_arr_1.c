/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arr_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 16:14:18 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/01 11:49:46 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <stdlib.h>

int8_t	ft_printf_arr_init(t_ft_printf_arr *src, size_t cap)
{
	GRD(src == 0 || cap == 0, -1);
	ft_printf_bzero(src, sizeof(t_ft_printf_arr));
	GRD((src->ptr = malloc(cap)) == 0, -1);
	src->cap = cap;
	return (0);
}

int8_t	ft_printf_arr_reserve(t_ft_printf_arr *src, size_t sze)
{
	char	*tmp;

	GRD(src == 0, -1);
	GRD(src->cap == 0, -1);
	if (src->len + sze > src->cap)
	{
		while (src->len + sze > src->cap)
			src->cap = 2 * src->cap;
		GRD((tmp = malloc(src->cap)) == 0, -1);
		ft_printf_memcpy(tmp, src->ptr, src->len);
		free(src->ptr);
		src->ptr = tmp;
	}
	return (0);
}

int8_t	ft_printf_arr_resize(t_ft_printf_arr *src, size_t sze)
{
	GRD(src == 0, -1);
	GRD(src->cap == 0, -1);
	if (src->len < sze)
	{
		GRD(ft_printf_arr_reserve(src, sze - src->len) == -1, -1);
		ft_printf_bzero(&src->ptr[src->len], sze - src->len);
	}
	src->len = sze;
	return (0);
}

char	*ft_printf_arr_tostr(t_ft_printf_arr *src)
{
	GRD(src == 0, 0);
	GRD(src->cap == 0, 0);
	if (src->len != src->cap)
		if (src->ptr[src->len] == 0)
			return (src->ptr);
	GRD(ft_printf_arr_append(src, "") == -1, 0);
	--src->len;
	return (src->ptr);
}

void	ft_printf_arr_dtr(t_ft_printf_arr *src)
{
	if (src == 0)
		return ;
	if (src->cap > 0)
		free(src->ptr);
	ft_printf_bzero(src, sizeof(t_ft_printf_arr));
}
