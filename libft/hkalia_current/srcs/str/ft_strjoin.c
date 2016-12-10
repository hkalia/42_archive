/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:44 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/09 11:41:36 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <str.h>
#include <ft_string.h>

char	*ft_strjoin(const char *src1, const char *src2)
{
	char	*ret;

	ret = 0;
	if (src1 && src2)
	{
		if (!(ret = ft_strnew(ft_strlen(src1) + ft_strlen(src2))))
			return (0);
		ft_strcpy(ret, src1);
		ft_strcat(ret, src2);
	}
	return (ret);
}
