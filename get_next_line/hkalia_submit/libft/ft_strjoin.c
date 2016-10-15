/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:44 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/28 08:53:00 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strjoin(const char *src1, const char *src2)
{
	char	*dst;
	size_t	src1_len;
	size_t	src2_len;
	size_t	i;

	src1_len = 0;
	src2_len = 0;
	i = -1;
	while (src1[src1_len])
		src1_len++;
	while (src2[src2_len])
		src2_len++;
	if (!(dst = (char*)malloc(sizeof(char) * (src1_len + src2_len))))
		return (NULL);
	while (++i < src1_len)
		dst[i] = src1[i];
	i = 0;
	while (i <= src2_len)
	{
		dst[src1_len + i] = src2[i];
		i++;
	}
	return (dst);
}
