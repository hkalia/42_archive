/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:10 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/15 15:21:53 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nbr.h>
#include <chr.h>
#include <unistd.h>

void	ft_putnbr_fd(int src, int fd)
{
	long	src_cpy;

	src_cpy = src;
	if (src_cpy < 0)
	{
		ft_putchar_fd('-', fd);
		src_cpy = -src_cpy;
	}
	if (src_cpy > 9)
	{
		ft_putnbr_fd(src_cpy / 10, fd);
		ft_putnbr_fd(src_cpy % 10, fd);
	}
	else
		ft_putchar_fd(src_cpy + '0', fd);
}
