/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:52:57 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/14 19:58:11 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <libft.h>
#include <stdio.h>
#include <unistd.h>

int		main(void)
{
	t_arr	test;

	GRD(arr_insertat(&test, 0, "hello", 5) == -1, -1);
	ft_putnbr(test.len);
	write(1, " ", 1);
	ft_putnbr(test.cap);
	write(1, " ", 1);
	write(1, test.arr, test.len);
	write(1, "\n", 1);

	GRD(arr_insertat(&test, 0, "smerch", 6) == -1, -1);
	ft_putnbr(test.len);
	write(1, " ", 1);
	ft_putnbr(test.cap);
	write(1, " ", 1);
	write(1, test.arr, test.len);
	write(1, "\n", 1);

	GRD(arr_insertat(&test, 100, "word", 4) == -1, -1);
	ft_putnbr(test.len);
	write(1, " ", 1);
	ft_putnbr(test.cap);
	write(1, " ", 1);
	write(1, test.arr, test.len);
	write(1, "\n", 1);

	GRD(arr_removeat(&test, 11, 89) == -1, -1);
	ft_putnbr(test.len);
	write(1, " ", 1);
	ft_putnbr(test.cap);
	write(1, " ", 1);
	write(1, test.arr, test.len);
	write(1, "\n", 1);

	arr_dtr(&test);
	return (0);
}
