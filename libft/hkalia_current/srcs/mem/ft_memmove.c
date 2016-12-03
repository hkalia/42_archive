/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:37:49 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/27 10:23:22 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src_cpy;
	unsigned char	*dst_cpy;

	src_cpy = (unsigned char *)src;
	dst_cpy = (unsigned char *)dst;
	if (src_cpy < dst_cpy)
	{
		src_cpy = src_cpy + len - 1;
		dst_cpy = dst_cpy + len - 1;
		while (len-- > 0)
			*dst_cpy-- = *src_cpy--;
	}
	else
	{
		while (len-- > 0)
			*dst_cpy++ = *src_cpy++;
	}
	return (dst);
}
