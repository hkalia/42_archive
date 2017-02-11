/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:40:08 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/29 16:22:31 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <str.h>

int		ft_strnequ(const char *src1, const char *src2, size_t len)
{
	size_t	i;

	if (src1 == 0 || src2 == 0)
		return (0);
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
