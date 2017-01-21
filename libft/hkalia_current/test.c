/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:02:27 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/21 14:50:35 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fcntl.h>
#include <stdio.h>

int		compare(const void *a, const void *b, size_t elm)
{
	(void)elm;
	return (*(int *)a - *(int *)b);
}

int	main(void)
{
	int		test[10] = {12, -21, 400, 50, 25, 6, 61, 4, 1, 8};
	size_t	i;
	t_arr	arr;

	arr_init(&arr, 10, sizeof(int));
	arr_insertat(&arr, 0, test, 10);
	i = 0;
	while (i < arr.len)
	{
		printf("%d\n", *(int *)ARR_INDEX(&arr, i));
		++i;
	}
	printf("\n\n\n");
	arr_qsort(&arr, compare);
	i = 0;
	while (i < arr.len)
	{
		printf("%d\n", *(int *)ARR_INDEX(&arr, i));
		++i;
	}
	return (0);
}
