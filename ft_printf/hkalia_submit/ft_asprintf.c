/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:43:18 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/26 17:14:41 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_asprintf(char **ret, const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	if (*format == '\0')
	{
		*ret = ft_strnew(0);
		return (0);
	}
	va_end(ap);
	return (0);
}
