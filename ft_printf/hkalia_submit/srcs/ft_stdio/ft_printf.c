/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:50:32 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/13 12:15:17 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <unistd.h>

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	*ret;
	int		r;

	if (fmt == 0 || *fmt == 0)
		return (0);
	va_start(ap, fmt);
	r = ft_vasprintf(&ret, fmt, &ap);
	write(1, ret, ft_strlen_2(ret));
	ft_strdel(&ret);
	va_end(ap);
	return (r);
}
