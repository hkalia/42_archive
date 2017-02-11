/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 14:48:59 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/21 14:49:05 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mem.h>
#include <stdlib.h>

void	*ft_memalloc(size_t len)
{
	unsigned char	*new_cpy;
	void			*new;

	GRD(len == 0, 0);
	GRD((new = malloc(len)) == 0, 0);
	new_cpy = (unsigned char *)new;
	while (len--)
		*new_cpy++ = 0;
	return (new);
}
