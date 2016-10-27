/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:37:55 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/26 14:21:35 by hkalia           ###   ########.fr       */
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
