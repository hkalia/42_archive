/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:32:50 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/28 20:07:40 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <fcntl.h>
#include <strings.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#define BUFF_SIZE 4096

int		main(int argc, char **argv)
{
	int		r;
	int		fd;
	char	buf[BUFF_SIZE] = {0};

	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		r = ft_printf(argv[1]);
		ft_putnbr(r);
	}
	else
	{
		read(fd, buf, BUFF_SIZE);
		r = ft_printf(buf);
		ft_putnbr(r);
	}
	return (0);
}
