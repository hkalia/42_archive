/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:51 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/27 14:37:15 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strmap(const char *src, char (*f)(char))
{
	char	*new;
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = 0;
	if (*src)
		while (src[src_len])
			src_len++;
	if (!(new = (char *)malloc(sizeof(char) * (src_len + 1))))
		return (NULL);
	while (i < src_len)
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	i = -1;
	while (new[++i])
		new[i] = f(new[i]);
	return (new);
}
