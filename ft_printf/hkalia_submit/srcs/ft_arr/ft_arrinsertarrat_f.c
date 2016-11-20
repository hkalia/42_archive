/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrinsertarrat_f.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 12:38:51 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/19 18:43:55 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_arr.h>

static int8_t	case2(t_arr **dst, size_t i, t_arr **src)
{
	t_arr	*tmp;
	size_t	j;

	FT_ARR_GRD(!(tmp = ft_arrnew((*dst)->arr_len - i)), src, 0);
	j = i;
	while (j < (*dst)->arr_len)
		tmp->arr[tmp->arr_len++] = (*dst)->arr[j++];
	j = 0;
	while (j < (*src)->arr_len)
		(*dst)->arr[i++] = (*src)->arr[j++];
	j = 0;
	while (j < tmp->arr_len)
		(*dst)->arr[i++] = tmp->arr[j++];
	ft_arrdel(&tmp);
	ft_arrdel(src);
	return (1);
}

static int8_t	case1(t_arr **dst, size_t i, t_arr **src)
{
	t_arr	*tmp;
	size_t	j;
	size_t	k;

	if ((*dst)->arr_sze < i + (*src)->arr_len)
	{
		FT_ARR_GRD(!(tmp = ft_arrnew(i + (*src)->arr_len)), src, 0);
	}
	else
		FT_ARR_GRD(!(tmp = ft_arrnew((*dst)->arr_len + (*src)->arr_len))
					, src, 0);
	j = 0;
	while (j < (*dst)->arr_len && j < i)
		tmp->arr[tmp->arr_len++] = (*dst)->arr[j++];
	while (tmp->arr_len < i)
		++tmp->arr_len;
	k = 0;
	while (k < (*src)->arr_len)
		tmp->arr[tmp->arr_len++] = (*src)->arr[k++];
	while (j < (*dst)->arr_len)
		tmp->arr[tmp->arr_len++] = (*dst)->arr[j++];
	ft_arrdel(dst);
	*dst = tmp;
	ft_arrdel(src);
	return (1);
}

static int8_t	case0(t_arr **dst, size_t i, t_arr **src)
{
	size_t	j;

	FT_ARR_GRD(!(*dst = ft_arrnew(i + (*src)->arr_len)), src, 0);
	(*dst)->arr_len = i;
	j = 0;
	while (j < (*src)->arr_len)
		(*dst)->arr[(*dst)->arr_len++] = (*src)->arr[j++];
	ft_arrdel(src);
	return (1);
}

int8_t			ft_arrinsertarrat_f(t_arr **dst, size_t i, t_arr **src)
{
	size_t	j;

	FT_ARR_GRD(!dst, 0, 0);
	FT_ARR_GRD(!src, 0, 1);
	FT_ARR_GRD(!*src, 0, 1);
	FT_ARR_GRD((*src)->arr_len == 0, src, 1);
	if (!*dst)
		return (case0(dst, i, src));
	if ((*dst)->arr_sze - (*dst)->arr_len < (*src)->arr_len
		|| (*dst)->arr_sze < i + (*src)->arr_len)
		return (case1(dst, i, src));
	if (i < (*dst)->arr_len)
		return (case2(dst, i, src));
	j = 0;
	while (j < (*src)->arr_len)
		(*dst)->arr[i++] = (*src)->arr[j++];
	(*dst)->arr_len = i;
	ft_arrdel(src);
	return (1);
}
