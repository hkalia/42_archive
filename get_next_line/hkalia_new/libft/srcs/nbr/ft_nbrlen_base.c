/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:56:22 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/10 15:48:25 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nbr.h>

short	ft_nbrlen_base(uintmax_t src, short base)
{
	short	ret;

	ret = 0;
	if (src == 0)
		return (1);
	while (src != 0)
	{
		src = src / base;
		++ret;
	}
	return (ret);
}
