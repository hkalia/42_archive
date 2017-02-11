/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:44 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 13:09:05 by hkalia           ###   ########.fr       */
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
		GRD((ret = ft_strnew(ft_strlen(src1) + ft_strlen(src2))) == 0, 0);
		ft_strcpy(ret, src1);
		ft_strcat(ret, src2);
	}
	return (ret);
}
