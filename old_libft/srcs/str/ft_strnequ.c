/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:40:08 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 12:27:16 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <str.h>

int		ft_strnequ(const char *src1, const char *src2, size_t len)
{
	size_t	i;

	GRD(src1 == 0 || src2 == 0, 0);
	i = 0;
	while ((*src1 != '\0' || *src2 != '\0') && i < len)
	{
		if (*src1 != *src2)
			return (0);
		src1++;
		src2++;
		i++;
	}
	return (1);
}
