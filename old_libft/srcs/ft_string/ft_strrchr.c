/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 20:51:36 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 11:56:17 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

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
	return (0);
}
