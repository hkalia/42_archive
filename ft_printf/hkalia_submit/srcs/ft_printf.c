/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:36:25 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/28 20:39:59 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		dispatcher(const char **fmt, va_list *ap)
{
	const char	*fmt_cpy;

	fmt_cpy = *fmt;
	if (*(fmt_cpy + 1) == '%')
	{
		write(1, "%", 1);
		*fmt += 2;
		return (1);
	}
	(void)ap;
	return (0);
}

void	iterator(const char *fmt, int *ret, va_list *ap)
{
	int		i;
	int		j;

	while (*fmt)
	{
		i = 0;
		if (*fmt == '%')
		{
			j = 0;
			if ((*ret += dispatcher(&fmt, &(*ap))) < 0)
				return ;
		}
		else if (ft_strchr(fmt, '%') == 0)
		{
			*ret += write(1, fmt, ft_strlen(fmt));
			return ;
		}
		else
		{
			while (fmt[i] != '%')
				++i;
			*ret += write(1, fmt, i);
			fmt += i;
		}
	}
}

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		ret;

	ret = 0;
	if (fmt == 0 || *fmt == 0)
		return (0);
	if (ft_strchr(fmt, '%') == 0)
		return (write(1, fmt, ft_strlen(fmt)));
	else
	{
		va_start(ap, fmt);
		iterator(fmt, &ret, &ap);
		va_end(ap);
	}
	return (ret);
}
