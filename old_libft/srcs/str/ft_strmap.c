/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:51 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 12:26:59 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <str.h>
#include <ft_string.h>
#include <stdlib.h>

char	*ft_strmap(const char *src, char (*f)(char))
{
	char	*new;
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = 0;
	GRD(src == 0, 0);
	src_len = ft_strlen(src);
	GRD((new = malloc(sizeof(char) * (src_len + 1))) == 0, 0);
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
