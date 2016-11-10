/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:48:51 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/09 16:10:31 by hkalia           ###   ########.fr       */
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

int		main(void)
{
	char	test = 'h';
	int		r;
	char	*ret;

	r = ft_asprintf(&ret, "hello this is a test %-c, test complete", test);
	write(1, ret, ft_strlen_2(ret));
	ft_strdel(&ret);
	ft_putnbr(r);
	write(1, "\n\nSPACE\n\n", 9);
	r = asprintf(&ret, "hello this is a test %-c, test complete", test);
	write(1, ret, ft_strlen_2(ret));
	ft_strdel(&ret);
	ft_putnbr(r);
	return (0);
}

// int		main(void)
// {
// 	printf("%-*%", -20);
// 	return (0);
// }
