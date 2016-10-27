/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:40:11 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/14 12:30:48 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_custom.h>
#include <stdlib.h>

char	*ft_strnew(size_t len)
{
	char	*new;

	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (len)
	{
		new[len] = 0;
		--len;
	}
	new[len] = 0;
	return (new);
}
