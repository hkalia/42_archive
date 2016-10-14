/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:36:43 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/27 09:52:17 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *src, size_t len)
{
	unsigned char	*src_cpy;

	src_cpy = (unsigned char *)src;
	while (len--)
		*src_cpy++ = 0;
}
