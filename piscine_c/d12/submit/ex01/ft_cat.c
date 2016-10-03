/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 15:41:06 by hkalia            #+#    #+#             */
/*   Updated: 2016/07/27 15:41:07 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cat(char *file)
{
	char	buf[BUF_SIZE + 1];
	int		len;
	int		fl;

	if ((fl = open(file, O_RDONLY)) == -1)
		return (errno);
	while ((len = read(fl, buf, BUF_SIZE)) != 0)
	{
		buf[len] = '\0';
		ft_putstr(buf);
	}
	close(fl);
	return (0);
}
