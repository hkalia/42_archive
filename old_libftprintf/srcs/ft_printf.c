/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:50:32 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/01 10:54:26 by hkalia           ###   ########.fr       */
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
	GRD((r = ft_vasprintf(&ret, fmt, ap)) == -1, -1);
	GRD1(write(1, ret, r) == -1, free(ret), -1);
	free(ret);
	va_end(ap);
	return (r);
}

int		ft_vprintf(const char *fmt, va_list ap)
{
	char	*ret;
	int		r;

	if (fmt == 0 || *fmt == 0)
		return (0);
	GRD((r = ft_vasprintf(&ret, fmt, ap)) == -1, -1);
	GRD1(write(1, ret, r) == -1, free(ret), -1);
	free(ret);
	return (r);
}

int		ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	ap;
	char	*ret;
	int		r;

	if (fmt == 0 || *fmt == 0 || fd < 0)
		return (0);
	va_start(ap, fmt);
	GRD((r = ft_vasprintf(&ret, fmt, ap)) == -1, -1);
	GRD2(write(fd, ret, r) == -1, free(ret), va_end(ap), -1);
	free(ret);
	va_end(ap);
	return (r);
}

int		ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	char	*ret;
	int		r;

	if (fmt == 0 || *fmt == 0 || fd < 0)
		return (0);
	GRD((r = ft_vasprintf(&ret, fmt, ap)) == -1, -1);
	GRD1(write(fd, ret, r) == -1, free(ret), -1);
	free(ret);
	return (r);
}

int		ft_asprintf(char **ret, const char *fmt, ...)
{
	va_list	ap;
	int		r;

	if (fmt == 0 || *fmt == 0 || ret == 0)
		return (0);
	va_start(ap, fmt);
	GRD((r = ft_vasprintf(ret, fmt, ap)) == -1, -1);
	va_end(ap);
	return (r);
}
