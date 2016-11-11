/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:49:31 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/10 14:50:20 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdlib.h>

unsigned char	*ft_wctomb(wint_t c)
{
	unsigned char	*ret;

	if (!(ret = ft_calloc(5, sizeof(unsigned char))))
		return (0);
	if (c < (1 << 7))
		ret[0] = (unsigned char)(c);
	else if (c < (1 << 11))
	{
		ret[0] = (unsigned char)((c >> 6) | 0xC0);
		ret[1] = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 16))
	{
		ret[0] = (unsigned char)(((c >> 12)) | 0xE0);
		ret[1] = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		ret[2] = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 21))
	{
		ret[0] = (unsigned char)(((c >> 18)) | 0xF0);
		ret[1] = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
		ret[2] = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		ret[3] = (unsigned char)((c & 0x3F) | 0x80);
	}
	return (ret);
}
