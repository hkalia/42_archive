/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:07:35 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/10 15:48:39 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nbr.h>
#include <unistd.h>

void	ft_putnbr_base(long long src, int base)
{
	char const	*spec = "0123456789abcdef";
	long long	conv_nbr[64];
	int			i;

	if (src < 0)
	{
		write(1, "-", 1);
		src = -src;
	}
	i = 0;
	while (src != 0)
	{
		conv_nbr[i] = src % base;
		src = src / base;
		++i;
	}
	--i;
	while (i >= 0)
	{
		write(1, &(spec[conv_nbr[i]]), 1);
		--i;
	}
}
