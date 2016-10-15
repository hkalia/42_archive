/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:40:29 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/30 20:53:58 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static void		ft_strlen2(const char *src, size_t *len)
{
	while (src[*len])
		*len = *len + 1;
}

static char		*ft_null_assign(char *new)
{
	if (!(new = (char *)malloc(sizeof(char))))
		return (NULL);
	*new = '\0';
	return (new);
}

char			*ft_strtrim(const char *src)
{
	size_t	len;
	char	*new;

	len = 0;
	new = NULL;
	while (*src == ' ' || *src == '\n' || *src == '\t')
		src++;
	if (*src != '\0')
	{
		ft_strlen2(src, &len);
		while (src[len - 1] == ' ' || src[len - 1] == '\n'
				|| src[len - 1] == '\t')
			len--;
		if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		new[len--] = '\0';
		while (len)
		{
			new[len] = src[len];
			len--;
		}
		new[len] = src[len];
		return (new);
	}
	return (ft_null_assign(new));
}
