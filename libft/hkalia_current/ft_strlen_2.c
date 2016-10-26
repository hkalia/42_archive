/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:37:03 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/26 15:37:05 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen2(const char *src)
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
