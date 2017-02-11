/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 09:10:25 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 11:55:51 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
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
	GRD((dst = (char *)malloc(sizeof(char) * (src_len + 1))) == 0, 0);
	while (i < src_len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
