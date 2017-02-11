/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extras_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 12:23:38 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/01 10:02:47 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_printf_bzero(void *src, size_t len)
{
	unsigned char	*src_cpy;

	src_cpy = (unsigned char *)src;
	while (len--)
		*src_cpy++ = 0;
}

void	*ft_printf_memset(void *dst, int src, size_t len)
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

void	*ft_printf_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_cpy;
	const unsigned char	*src_cpy;

	dst_cpy = (unsigned char *)dst;
	src_cpy = (const unsigned char *)src;
	while (len-- > 0)
		*dst_cpy++ = *src_cpy++;
	return (dst);
}

void	*ft_printf_memmove(void *dst, const void *src, size_t len)
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
