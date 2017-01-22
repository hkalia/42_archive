/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:05:21 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/19 12:59:40 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <ft_string.h>
#include <stdlib.h>

int8_t	arr_init(t_arr *src, size_t cap, size_t elm)
{
	GRD(src == 0 || elm == 0 || cap == 0, -1);
	ft_bzero(src, sizeof(t_arr));
	GRD(!(src->arr = malloc(cap * elm)), -1);
	src->elm = elm;
	src->cap = cap;
	return (0);
}
