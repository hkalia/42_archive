/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:40:26 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/27 16:08:09 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(const char *src, unsigned int src_i, size_t len)
{
	char	*new;
	size_t	i;

	if (src == 0)
		return (0);
	i = 0;
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (src_i--)
		src++;
	while (i < len && src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[len] = '\0';
	return (new);
}
