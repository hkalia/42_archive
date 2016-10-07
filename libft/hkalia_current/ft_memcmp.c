/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:37:40 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/26 14:32:34 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *src1, const void *src2, size_t len)
{
	unsigned char	*src1_cpy;
	unsigned char	*src2_cpy;

	src1_cpy = (unsigned char*)src1;
	src2_cpy = (unsigned char*)src2;
	while (len > 0 && *src1_cpy == *src2_cpy)
	{
		src1_cpy++;
		src2_cpy++;
		len--;
	}
	if (len == 0)
		return (0);
	else
		return (*src1_cpy - *src2_cpy);
}
