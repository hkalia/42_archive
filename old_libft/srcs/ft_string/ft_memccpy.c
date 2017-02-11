/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:26:22 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 11:56:47 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

void	*ft_memccpy(void *dst, const void *src, int src_x, size_t len)
{
	const unsigned char	*src_cpy;
	unsigned char		*dst_cpy;
	unsigned char		src_x_cpy;

	src_cpy = (const unsigned char *)src;
	dst_cpy = (unsigned char *)dst;
	src_x_cpy = (unsigned char)src_x;
	while (len--)
	{
		if ((*dst_cpy++ = *src_cpy++) == src_x_cpy)
			return (dst_cpy);
	}
	return (0);
}
