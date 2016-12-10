/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:07 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/10 15:49:03 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nbr.h>
#include <unistd.h>

static void	print_char(char src)
{
	write(1, &src, 1);
}

void		ft_putnbr(int src)
{
	long	src_cpy;

	src_cpy = src;
	if (src_cpy < 0)
	{
		write(1, "-", 1);
		src_cpy = -src_cpy;
	}
	if (src_cpy > 9)
	{
		ft_putnbr(src_cpy / 10);
		ft_putnbr(src_cpy % 10);
	}
	else
		print_char(src_cpy + '0');
}
