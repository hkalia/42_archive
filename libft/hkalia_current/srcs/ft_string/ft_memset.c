/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:37:55 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 11:56:41 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

void	*ft_memset(void *dst, int src, size_t len)
{
	unsigned char	*dst_cpy;

	dst_cpy = (unsigned char *)dst;
	while (len > 0)
	{
		*dst_cpy = (unsigned char)src;
		len--;
		dst_cpy++;
	}
	return (dst);
}
