/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:50:32 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/24 13:14:37 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	ap;
	char	*ret;
	int		r;

	if (fmt == 0 || *fmt == 0 || fd < 0)
		return (0);
	va_start(ap, fmt);
	GRD((r = ft_vasprintf(&ret, fmt, &ap)) == -1, -1);
	GRD2(write(fd, ret, r) == -1, free(ret), va_end(ap), -1);
	free(ret);
	va_end(ap);
	return (r);
}
