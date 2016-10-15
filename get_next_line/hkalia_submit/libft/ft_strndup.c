/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 09:10:25 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/29 16:44:23 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strndup(const char *src, size_t len)
{
	size_t	i;
	size_t	src_len;
	char	*dst;

	i = 0;
	src_len = 0;
	while (src[src_len] && src_len < len)
		src_len++;
	if (!(dst = (char *)malloc(sizeof(char) * (src_len + 1))))
		return (NULL);
	while (i < src_len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
