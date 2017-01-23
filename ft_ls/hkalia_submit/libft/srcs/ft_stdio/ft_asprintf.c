/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:50:32 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/23 14:20:15 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_asprintf(char **ret, const char *fmt, ...)
{
	va_list	ap;
	int		r;

	if (fmt == 0 || *fmt == 0 || ret == 0)
		return (0);
	va_start(ap, fmt);
	GRD((r = ft_vasprintf(ret, fmt, &ap)) == -1, -1);
	va_end(ap);
	return (r);
}
