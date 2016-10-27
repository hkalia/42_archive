/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:26:22 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/30 16:26:32 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

void	*ft_memccpy(void *dst, const void *src, int src_x, size_t len)
{
	unsigned char	*src_cpy;
	unsigned char	*dst_cpy;
	unsigned char	src_x_cpy;

	src_cpy = (unsigned char *)src;
	dst_cpy = (unsigned char *)dst;
	src_x_cpy = (unsigned char)src_x;
	while (len)
	{
		*dst_cpy = *src_cpy;
		if (*src_cpy == src_x_cpy)
			return ((void *)(dst_cpy + 1));
		src_cpy++;
		dst_cpy++;
		len--;
	}
	return (NULL);
}
