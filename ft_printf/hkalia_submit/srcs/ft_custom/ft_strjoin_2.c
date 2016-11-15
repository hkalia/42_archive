/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:42:50 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/14 11:46:51 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_custom.h>
#include <ft_string.h>
#include <stdlib.h>

char	*ft_strjoin_2(char *src1, char *src2)
{
	char	*ret;

	ret = 0;
	if (src1 && src2)
	{
		if (!(ret = ft_strnew(ft_strlen(src1) + ft_strlen(src2))))
			return (0);
		ft_strcpy(ret, src1);
		ft_strcat(ret, src2);
		free(src1);
		free(src2);
	}
	return (ret);
}
