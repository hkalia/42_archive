/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strextend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:29:38 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/08 15:34:12 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <str.h>
#include <ft_string.h>

char	*ft_strextend(char *src, size_t len)
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
