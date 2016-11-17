/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:48:51 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/16 17:23:06 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <strings.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

/*
**	0x10000
*/

int		main(void)
{
	int			r;
	intmax_t	test;

	test = -3;
	setlocale(LC_ALL, "");
	r = ft_printf("%d", -3);
	ft_putnbr(r);
	write(1, "\n\n\n", 3);
	r = printf("%d", -3);
	ft_putnbr(r);
	return (0);
}
