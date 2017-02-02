/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:40:26 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 12:28:38 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <str.h>
#include <stdlib.h>

char	*ft_strsub(const char *src, unsigned int src_i, size_t len)
{
	char	*new;
	size_t	i;

	if (src == 0)
		return (0);
	i = 0;
	GRD((new = malloc(sizeof(char) * (len + 1))) == 0, 0);
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
