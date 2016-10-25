/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 12:14:37 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/22 12:14:41 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew2(char *src, size_t len)
{
	char	*ret;

	if (src != 0 && *src != '\0')
	{
		if (!(ret = ft_strnew(ft_strlen(src) + len)))
		{
			ft_strdel(&src);
			return (0);
		}
		ft_strcpy(ret, src);
		ft_strdel(&src);
	}
	else if (!(ret = ft_strnew(len)))
		return (0);
	return (ret);
}
