/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:49 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 11:56:34 by hkalia           ###   ########.fr       */
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
