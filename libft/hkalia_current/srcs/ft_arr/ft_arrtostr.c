/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:35:47 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/21 18:09:32 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_arr.h>

char	*ft_arrtostr(t_arr *src)
{
	FT_GRD(!src, 0);
	if (src->len != src->sze)
		if (src->arr[src->len] == 0)
			return ((char *)src->arr);
	FT_GRD(!ft_arrinsertat(src, src->len, "", 1), 0);
	--src->len;
	return ((char *)src->arr);
}
