/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 20:51:36 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/30 20:58:41 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *src, int src_x)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	while (i > 0)
	{
		if (src[i] == src_x)
			return ((char *)src + i);
		i--;
	}
	if (src[i] == src_x)
		return ((char *)src + i);
	return (NULL);
}
