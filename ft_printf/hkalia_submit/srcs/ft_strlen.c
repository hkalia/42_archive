/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:49 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/26 17:26:45 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

size_t	ft_strlen(const char *src)
{
	const char	*src_cpy;

	src_cpy = src;
	while (*src_cpy)
		++src_cpy;
	return (src_cpy - src);
}
