/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:50:32 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/31 14:07:02 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <stdlib.h>
#include <unistd.h>

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	*ret;
	int		r;

	if (fmt == 0 || *fmt == 0)
		return (0);
	va_start(ap, fmt);
	GRD((r = ft_vasprintf(&ret, fmt, &ap)) == -1, -1);
	write(1, ret, r);
	free(ret);
	va_end(ap);
	return (r);
}
