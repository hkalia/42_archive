/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:40:23 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/27 08:56:45 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *big, const char *lit)
{
	unsigned char	*big_cpy;
	unsigned char	*lit_cpy;

	if (*lit == '\0')
		return ((char *)big);
	while (*big)
	{
		if (*big == *lit)
		{
			big_cpy = (unsigned char *)big;
			lit_cpy = (unsigned char *)lit;
			while (*big_cpy == *lit_cpy && *lit_cpy != '\0')
			{
				big_cpy++;
				lit_cpy++;
			}
			if (*lit_cpy == '\0')
				return (char *)big;
		}
		big++;
	}
	return (NULL);
}
