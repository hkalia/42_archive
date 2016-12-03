/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:37:03 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/03 15:44:06 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_custom.h>

size_t	ft_strlen_2(const char *src)
{
	const char	*src_cpy;

	src_cpy = src;
	if (src_cpy == 0)
		return (0);
	else
		while (*src_cpy)
			++src_cpy;
	return (src_cpy - src);
}
