/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:37:37 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 11:56:45 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

void	*ft_memchr(const void *src, int src_x, size_t len)
{
	unsigned char	*src_cpy;

	src_cpy = (unsigned char*)src;
	while (len > 0 && *src_cpy != (unsigned char)src_x)
	{
		len--;
		src_cpy++;
	}
	if (len == 0)
		return (NULL);
	else
		return (src_cpy);
}
