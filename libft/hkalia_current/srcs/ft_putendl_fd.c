/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:39:04 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/29 11:43:40 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_custom.h>
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
