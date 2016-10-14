/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 14:43:55 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/14 14:44:05 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_putnbrstr(int *src, int stop)
{
	size_t	i;

	i = 0;
	while (src[i] != stop)
	{
		ft_putnbr(src[i]);
		ft_putchar('\n');
		i++;
	}
}
