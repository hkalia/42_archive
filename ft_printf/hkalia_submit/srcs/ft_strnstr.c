/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:40:13 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/22 15:40:14 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	unsigned char	*big_cpy;
	unsigned char	*lit_cpy;
	size_t			len_cpy;

	if (*lit == '\0')
		return ((char *)big);
	while (*big && len)
	{
		if (*big == *lit)
		{
			big_cpy = (unsigned char *)big;
			lit_cpy = (unsigned char *)lit;
			len_cpy = len;
			while (*big_cpy == *lit_cpy && *lit_cpy != '\0' && len_cpy--)
			{
				big_cpy++;
				lit_cpy++;
			}
			if (*lit_cpy == '\0')
				return (char *)big;
		}
		len--;
		big++;
	}
	return (NULL);
}
