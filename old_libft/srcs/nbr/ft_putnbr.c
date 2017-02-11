/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:07 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 12:18:02 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nbr.h>
#include <chr.h>

void		ft_putnbr(intmax_t src)
{
	if (src < 0)
	{
		ft_putchar('-');
		src = -src;
	}
	if (src > 9)
	{
		ft_putnbr(src / 10);
		ft_putnbr(src % 10);
	}
	else
		ft_putchar(src + '0');
}
