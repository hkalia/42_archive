/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:40:29 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 12:31:02 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <str.h>
#include <mem.h>
#include <ft_string.h>
#include <stdlib.h>

static char		*ft_null_assign(char *new)
{
	GRD((new = ft_memalloc(sizeof(char))) == 0, 0);
	return (new);
}

char			*ft_strtrim(const char *src)
{
	size_t	len;
	char	*new;

	len = 0;
	new = 0;
	while (src != 0 && (*src == ' ' || *src == '\n' || *src == '\t'))
		src++;
	if (src != 0 && *src != '\0')
	{
		len = ft_strlen(src);
		while (src[len - 1] == ' ' || src[len - 1] == '\n'
				|| src[len - 1] == '\t')
			len--;
		GRD((new = malloc(sizeof(char) * (len + 1))) == 0, 0);
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
