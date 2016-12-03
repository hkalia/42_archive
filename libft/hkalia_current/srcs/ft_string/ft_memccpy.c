/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:26:22 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/03 09:53:17 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <stdint.h>

void	*ft_memccpy(void *dst, const void *src, int src_x, size_t len)
{
	const unsigned char	*src_cpy;
	unsigned char		*dst_cpy;
	unsigned char		src_x_cpy;

	if (len)
	{
		src_cpy = (const unsigned char *)src;
		dst_cpy = (unsigned char *)dst;
		src_x_cpy = (char)src_x;
		while (1)
		{
			if ((*dst_cpy++ = *src_cpy++) == src_x)
				return (dst);
			if (--len == 0)
				break ;
		}
	}
	return (0);
}
