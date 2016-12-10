/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:53:20 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/14 12:30:53 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <str.h>
#include <stdarg.h>
#include <stdlib.h>

void	ft_strdel_2(int count, ...)
{
	va_list	ap;
	char	**src;

	va_start(ap, count);
	while ((src = va_arg(ap, char **)) && count--)
	{
		if (src != 0 && *src != 0)
		{
			free(*src);
			*src = NULL;
		}
	}
}
