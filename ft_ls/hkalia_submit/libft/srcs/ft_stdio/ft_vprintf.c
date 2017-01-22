/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:50:32 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/24 13:11:06 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_vprintf(const char *fmt, va_list *ap)
{
	char	*ret;
	int		r;

	if (fmt == 0 || *fmt == 0)
		return (0);
	GRD((r = ft_vasprintf(&ret, fmt, ap)) == -1, -1);
	write(1, ret, r);
	free(ret);
	return (r);
}
