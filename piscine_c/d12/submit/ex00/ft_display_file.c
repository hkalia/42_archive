/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 14:46:30 by hkalia            #+#    #+#             */
/*   Updated: 2016/07/27 14:46:31 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_display_file(char *file)
{
	char	buf[BUF_SIZE + 1];
	int		len;
	int		fl;

	if ((fl = open(file, O_RDONLY)) == -1)
		return (1);
	while ((len = read(fl, buf, BUF_SIZE)) != 0)
	{
		buf[len] = '\0';
		ft_putstr(buf);
	}
	close(fl);
	return (0);
}
