/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 18:05:17 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/01 15:25:26 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>

#define SWAP(a, b, c) c = a; a = b; b = c

int		main(void)
{
	int	test1 = 1;
	int	test2 = 2;
	int	tmp;

	SWAP(test1, test2, tmp);
	printf("%d %d\n", test1, test2);
	return (0);
}
