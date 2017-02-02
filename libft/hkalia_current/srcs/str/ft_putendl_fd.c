/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:04 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 12:20:57 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <str.h>
#include <chr.h>
#include <unistd.h>

void	ft_putendl_fd(int fd, const char *src)
{
	while (*src)
	{
		write(fd, src, 1);
		src++;
	}
	ft_putchar_fd(fd, '\n');
}
