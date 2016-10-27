/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:07 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/29 11:39:12 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_custom.h>
#include <unistd.h>

void	ft_putnbr(int src)
{
	long	src_cpy;

	src_cpy = src;
	if (src_cpy < 0)
	{
		ft_putchar('-');
		src_cpy = -src_cpy;
	}
	if (src_cpy > 9)
	{
		ft_putnbr(src_cpy / 10);
		ft_putnbr(src_cpy % 10);
	}
	else
		ft_putchar(src_cpy + '0');
}
