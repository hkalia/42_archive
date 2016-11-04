/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:48:51 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/03 15:51:44 by hkalia           ###   ########.fr       */
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

#define BUFF_SIZE 4096

int		main(int argc, char **argv)
{
	int		r;
	char	*ret;

	if (argc == 2)
	{
		r = ft_asprintf(&ret, argv[1]);
		write(1, ret, ft_strlen_2(ret));
		ft_strdel(&ret);
		ft_putnbr(r);
	}
	else
		write(1, "give me input plz...\n", 21);
	return (0);
}
