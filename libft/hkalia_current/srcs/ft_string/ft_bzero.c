/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:36:43 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/03 09:52:21 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <stdint.h>

void	ft_bzero(void *src, size_t len)
{
	unsigned char	*src_cpy;

	src_cpy = (unsigned char *)src;
	while (len--)
		*src_cpy++ = 0;
}
