/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:52:57 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/14 17:06:17 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <libft.h>
#include <stdio.h>

int		main(void)
{
	t_arr	test;

	arr_init(&test, 10);
	arr_insertat(&test, 0, "hello", 5);
	printf("%s\n", test.arr);
	return 0;
}
