/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:50:32 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/24 13:14:42 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_vdprintf(int fd, const char *fmt, va_list *ap)
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
