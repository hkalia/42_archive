/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:02:18 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/19 09:42:24 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_arr.h>
#include <ft_stdlib.h>

t_arr	*ft_arrnew(const size_t arr_sze)
{
	t_arr	*ret;

	if (!(ret = ft_calloc(1, sizeof(t_arr))))
		return (0);
	ret->arr_len = 0;
	ret->arr_sze = arr_sze;
	if (!(ret->arr = ft_calloc(ret->arr_sze, sizeof(uint8_t))))
		return (0);
	return (ret);
}
