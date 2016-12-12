/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:44:19 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/12 11:08:28 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mem.h>
#include <ft_string.h>
#include <str.h>
#include <stdlib.h>

void	*ft_reallocf(void *src, size_t src_sze, size_t sze)
{
	void	*ret;

	GRD(sze == 0, 0);
	if (src == 0)
		GRD((ret = malloc(sze)) == 0, 0);
	else if (src_sze < sze)
	{
		GRD((ret = malloc(sze)) == 0, 0);
		ft_memcpy(ret, src, src_sze);
		ft_strdel(src);
	}
	else
		ret = src;
	return (ret);
}
