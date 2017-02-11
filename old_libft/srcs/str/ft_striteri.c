/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:41 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 12:22:40 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <str.h>

void	ft_striteri(char *src, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (src != 0 && f != 0)
	{
		i = 0;
		while (src[i])
		{
			f(i, &src[i]);
			i++;
		}
	}
}
