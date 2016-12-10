/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:37:32 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/10 15:46:56 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mem.h>
#include <stdlib.h>

void	*ft_memalloc(size_t len)
{
	unsigned char	*new_cpy;
	void			*new;

	new = NULL;
	if (len)
	{
		new = malloc(len);
		if (new)
		{
			new_cpy = (unsigned char *)new;
			while (len--)
				*new_cpy++ = 0;
		}
	}
	return (new);
}
