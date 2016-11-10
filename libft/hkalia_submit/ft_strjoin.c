/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:44 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/08 15:55:04 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_custom.h>

char	*ft_strjoin(const char *src1, const char *src2)
{
	char	*dst;
	size_t	src1_len;
	size_t	src2_len;
	size_t	i;

	src1_len = ft_strlen(src1);
	src2_len = ft_strlen(src2);
	i = -1;
	if (!(dst = ft_strnew(src1_len + src2_len))))
		return (0);
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
