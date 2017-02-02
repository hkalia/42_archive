/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:40:02 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 11:56:31 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

int		ft_strncmp(const char *src1, const char *src2, size_t len)
{
	unsigned char src1_cpy;
	unsigned char src2_cpy;

	while (len-- > 0)
	{
		src1_cpy = (unsigned char)*src1++;
		src2_cpy = (unsigned char)*src2++;
		if (src1_cpy != src2_cpy)
			return (src1_cpy - src2_cpy);
		if (src1_cpy == '\0')
			return (0);
	}
	return (0);
}
