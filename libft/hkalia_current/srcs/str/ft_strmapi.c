/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:54 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 12:27:51 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <str.h>
#include <ft_string.h>
#include <stdlib.h>

char	*ft_strmapi(const char *src, char (*f)(unsigned int, char))
{
	char			*new;
	size_t			src_len;
	unsigned int	i;

	i = 0;
	GRD(src == 0, 0);
	src_len = ft_strlen(src);
	GRD((new = malloc(sizeof(char) * (src_len + 1))) == 0, 0);
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
