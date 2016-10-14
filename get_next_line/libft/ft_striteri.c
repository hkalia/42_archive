/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:41 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/27 14:36:27 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_striteri(char *src, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		f(i, &src[i]);
		i++;
	}
}
