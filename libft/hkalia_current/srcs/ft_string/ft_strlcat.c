/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:46 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 11:56:36 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;
	size_t	dst_len_empty;

	i = -1;
	dst_len = 0;
	while (dst_len < len && dst[dst_len])
		dst_len++;
	src_len = 0;
	while (src[src_len])
		src_len++;
	dst_len_empty = len - dst_len;
	dst += dst_len;
	if (dst_len_empty > 0)
	{
		while (++i < dst_len_empty && src[i] != '\0')
			dst[i] = src[i];
		dst[i - (i == dst_len_empty)] = '\0';
	}
	return (dst_len + src_len);
}
