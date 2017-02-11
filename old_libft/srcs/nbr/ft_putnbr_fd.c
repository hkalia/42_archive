/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:10 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 12:17:03 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nbr.h>
#include <chr.h>

void	ft_putnbr_fd(int fd, intmax_t src)
{
	if (src < 0)
	{
		ft_putchar_fd(fd, '-');
		src = -src;
	}
	if (src > 9)
	{
		ft_putnbr_fd(fd, src / 10);
		ft_putnbr_fd(fd, src % 10);
	}
	else
		ft_putchar_fd(fd, src + '0');
}
