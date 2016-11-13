/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:49:31 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/13 10:56:35 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdlib.h>
#include <ft_string.h>

int		ft_wctomb(char *s, wchar_t wchar)
{
	if (s == 0)
		return (0);
	if (wchar < (1 << 7))
		s[0] = (unsigned char)(wchar);
	else if (wchar < (1 << 11))
	{
		s[0] = (unsigned char)((wchar >> 6) | 0xC0);
		s[1] = (unsigned char)((wchar & 0x3F) | 0x80);
	}
	else if (wchar - 0xd800u < 0x800)
		return (-1);
	else if (wchar < (1 << 16))
	{
		s[0] = (unsigned char)(((wchar >> 12)) | 0xE0);
		s[1] = (unsigned char)(((wchar >> 6) & 0x3F) | 0x80);
		s[2] = (unsigned char)((wchar & 0x3F) | 0x80);
	}
	else if (wchar < (1 << 21))
	{
		s[0] = (unsigned char)(((wchar >> 18)) | 0xF0);
		s[1] = (unsigned char)(((wchar >> 12) & 0x3F) | 0x80);
		s[2] = (unsigned char)(((wchar >> 6) & 0x3F) | 0x80);
		s[3] = (unsigned char)((wchar & 0x3F) | 0x80);
	}
	else
		return (-1);
	return (ft_strlen(s));
}
