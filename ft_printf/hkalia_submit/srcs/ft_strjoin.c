/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:44 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/02 13:58:00 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_custom.h>
#include <ft_string.h>
#include <stdlib.h>

char	*ft_strjoin(const char *src1, const char *src2)
{
	char	*dst;
	size_t	src1_len;
	size_t	src2_len;
	size_t	i;

	if (src1 == 0 || src2 == 0)
		return (0);
	src1_len = ft_strlen(src1);
	src2_len = ft_strlen(src2);
	if (!(dst = (char*)malloc(sizeof(char) * (src1_len + src2_len))))
		return (0);
	i = -1;
	while (++i < src1_len)
		dst[i] = src1[i];
	i = -1;
	while (++i <= src2_len)
		dst[src1_len + i] = src2[i];
	return (dst);
}
