/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:48:51 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/19 18:47:41 by hkalia           ###   ########.fr       */
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
#include <stdio.h>
#include <limits.h>

/*
**	0x10000
*/

int		main(void)
{
	t_arr	*test;
	t_arr	*test1;
	char	*s;

	test = 0;
	test1 = 0;
	s = ft_calloc(5, sizeof(char));
	ft_strcpy(s, "test");
	FT_ARR_GRD(!ft_arrinsertat_f(&test, 0, s, 4), 0, 0);
	FT_ARR_GRD(!ft_arrinsertarrat_f(&test1, 5, &test), 0, 0);
	// ft_putnbr(test->arr_sze);
	// write(1, " ", 1);
	// ft_putnbr(test->arr_len);
	// write(1, " ", 1);
	// write(1, test->arr, test->arr_len);
	// write(1, "\n", 1);
	ft_putnbr(test1->arr_sze);
	write(1, " ", 1);
	ft_putnbr(test1->arr_len);
	write(1, " ", 1);
	write(1, test1->arr, test1->arr_len);
	ft_arrdel(&test);
	ft_arrdel(&test1);
	return (0);
}
