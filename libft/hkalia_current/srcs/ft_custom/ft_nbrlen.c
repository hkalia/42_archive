/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 09:38:56 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/16 17:23:57 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_custom.h>

short	ft_nbrlen(intmax_t src)
{
	short	ret;

	if (src == 0)
		return (1);
	ret = src < 0 ? 1 : 0;
	while (src != 0)
	{
		src = src / 10;
		++ret;
	}
	return (ret);
}
