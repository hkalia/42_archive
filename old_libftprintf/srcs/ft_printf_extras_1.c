/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extras.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 12:23:38 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/01 10:02:50 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <stdlib.h>

size_t	ft_printf_strlen(const char *src)
{
	const char	*src_cpy;

	src_cpy = src;
	while (*src_cpy)
		++src_cpy;
	return (src_cpy - src);
}

char	*ft_printf_strdup(const char *src)
{
	size_t	i;
	size_t	src_len;
	char	*dst;

	i = 0;
	src_len = ft_printf_strlen(src);
	GRD((dst = malloc(sizeof(char) * (src_len + 1))) == 0, 0);
	while (i < src_len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_printf_strchr(const char *src, int src_x)
{
	while (*src != (char)src_x)
	{
		GRD(*src == 0, 0);
		src++;
	}
	return ((char *)src);
}
