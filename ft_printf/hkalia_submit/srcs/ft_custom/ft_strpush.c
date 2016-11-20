/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 09:57:10 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/17 17:02:11 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_custom.h>
#include <ft_stdlib.h>

char	*ft_strpush(char *dst, char *src)
{
	size_t	dst_len;
	size_t	src_len;
	char	*ret;

	if (!(dst_len = ft_strlen_2(dst)) || !(src_len = ft_strlen_2(src)))
		return (0);
	if (!(ret = ft_calloc(dst_len + src_len + 1, sizeof(char))))
		return (0);
	src_len = 0;
	while (src[src_len])
	{
		ret[src_len] = src[src_len];
		++src_len;
	}
	dst_len = 0;
	while (dst[dst_len])
	{
		ret[src_len + dst_len] = dst[dst_len];
		++dst_len;
	}
	free(dst);
	free(src);
	return (ret);
}
