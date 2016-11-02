/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:36:25 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/02 16:46:14 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <ft_custom.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	dispatcher(char **ret, const char **fmt, va_list *ap)
{
	char				*spec;
	t_printf_store		storage;
	t_printf_func_ptr	func_arr[ft_tbllen(PRINTF_SPEC)];
	int					i;

	STR_GUARD(*(++*fmt) == 0, ret, -1);
	conv_spec = PRINTF_SPEC;
	func_arr = PRINTF_FARR;
	i = 0;
	while (conv_spec[i])
	{
		if (**fmt == conv_spec[i])
		{
			++*fmt;
			if (test(ret) == -1)
				return (-1);
			return (1);
		}
		++i;
	}
	ft_strdel(ret);
	return (-1);
}

int	iterator(char **ret, const char *fmt, va_list *ap)
{
	int		i;

	if (!(*ret = ft_strnew(ft_strlen(fmt))))
		return (-1);
	while (*fmt)
	{
		i = ft_strlen(*ret);
		while (*fmt && *fmt != '%')
			(*ret)[i++] = *fmt++;
		if (*fmt && *fmt == '%')
			if (dispatcher(ret, &fmt, ap) == -1)
				return (-1);
	}
	return (ft_strlen(*ret));
}

int	ft_asprintf(char **ret, const char *fmt, ...)
{
	va_list	ap;
	int		r;

	if (fmt == 0 || *fmt == 0 || ret == 0)
		return (0);
	*ret = 0;
	if (ft_strchr(fmt, '%') == 0)
		return (((*ret = ft_strdup(fmt)) ? ft_strlen(fmt) : -1));
	va_start(ap, fmt);
	r = iterator(ret, fmt, &ap);
	va_end(ap);
	return (r);
}
