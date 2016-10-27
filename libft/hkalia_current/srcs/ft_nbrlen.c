/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 09:38:56 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/29 09:42:54 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_custom.h>

size_t	ft_nbrlen(ssize_t src)
{
	size_t	len;

	len = 0;
	if (src == 0)
		return (1);
	if (src < 0)
		len++;
	while (src != 0)
	{
		src = src / 10;
		len++;
	}
	return (len);
}
