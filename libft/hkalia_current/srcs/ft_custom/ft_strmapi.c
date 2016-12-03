/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:54 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/03 15:46:06 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_custom.h>
#include <stdlib.h>

char	*ft_strmapi(const char *src, char (*f)(unsigned int, char))
{
	char			*new;
	size_t			src_len;
	unsigned int	i;

	i = 0;
	if ((src_len = ft_strlen_2(src)) == 0)
		return (0);
	if (!(new = (char *)malloc(sizeof(char) * (src_len + 1))))
		return (NULL);
	while (i < src_len)
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	i = 0;
	while (new[i])
	{
		new[i] = f(i, new[i]);
		i++;
	}
	return (new);
}
