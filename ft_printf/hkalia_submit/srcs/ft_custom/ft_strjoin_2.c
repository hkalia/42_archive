/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:42:50 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/24 16:47:20 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_custom.h>
#include <ft_stdlib.h>
#include <stdlib.h>

char	*ft_strjoin_2(char *src1, char *src2)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (!(ret = ft_calloc(ft_strlen_2(src1) + ft_strlen_2(src2) + 1
		, sizeof(char))))
		return (0);
	i = 0;
	j = 0;
	if (src1)
		while (src1[j])
			ret[i++] = src1[j++];
	j = 0;
	if (src2)
		while (src2[j])
			ret[i++] = src2[j++];
	free(src1);
	free(src2);
	return (ret);
}
