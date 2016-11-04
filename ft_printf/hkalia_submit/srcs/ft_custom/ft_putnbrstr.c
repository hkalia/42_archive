/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 14:43:55 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/01 16:14:30 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_custom.h>
#include <unistd.h>

void	ft_putnbrstr(int *src, int stop)
{
	size_t	i;

	i = 0;
	while (src[i] != stop)
	{
		ft_putnbr(src[i]);
		write(1, "\n", 1);
		i++;
	}
}
