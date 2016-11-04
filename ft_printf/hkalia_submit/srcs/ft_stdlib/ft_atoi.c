/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:52:15 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/03 11:52:17 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdlib.h>

int		ft_atoi(const char *src)
{
	int					i;
	int					flg_neg;
	unsigned long long	ret;

	while (*src == ' ' || *src == '\f' || *src == '\t' || *src == '\n'
			|| *src == '\r' || *src == '\v')
		src++;
	flg_neg = (*src == '-' ? -1 : 1);
	src = (*src == '-' || *src == '+') ? src + 1 : src;
	while (*src == '0')
		src++;
	i = 0;
	ret = 0;
	while (src[i] && (src[i] >= '0' && src[i] <= '9'))
	{
		ret = ret * 10 + (src[i] - '0');
		i++;
	}
	if (i > 19 || ret >= 9223372036854775808ULL)
		return (flg_neg == 1 ? -1 : 0);
	return (ret * flg_neg);
}
