/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:37:32 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/27 13:38:50 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_custom.h>
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
