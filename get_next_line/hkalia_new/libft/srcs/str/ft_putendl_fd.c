/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:04 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/15 15:22:16 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <str.h>
#include <chr.h>
#include <unistd.h>

void	ft_putendl_fd(const char *src, int fd)
{
	while (*src)
	{
		write(fd, src, 1);
		src++;
	}
	ft_putchar_fd('\n', fd);
}
