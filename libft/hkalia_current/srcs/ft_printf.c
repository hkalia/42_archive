/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:36:25 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/26 16:36:27 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <ft_custom.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_printf(const char *format, ...)
{
	va_list	ap;

	if (*format == 0)
		return (0);
	if (ft_strchr(format, '%') == 0)
	{
		ft_putstr(format);
		return (ft_strlen(format));
	}
	else
	{
		va_start(ap, format);
		va_end(ap);
	}
	return (0);
}
