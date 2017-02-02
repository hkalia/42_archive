/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:34 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 11:55:12 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	src_len;
	char	*dst;

	i = 0;
	src_len = ft_strlen(src);
	GRD((dst = malloc(sizeof(char) * (src_len + 1))) == 0, 0);
	while (i < src_len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
