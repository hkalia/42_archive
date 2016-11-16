/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:48:51 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/16 13:06:37 by hkalia           ###   ########.fr       */
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
	int		r;

	setlocale(LC_ALL, "");
	r = ft_printf("%100ls", L"𐀀𐀀𐀀");
	write(1, "\n\n\n", 3);
	r = printf("%100ls", L"𐀀𐀀𐀀");
	return (0);
}
