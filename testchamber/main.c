/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 18:05:17 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/05 13:28:23 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>

int		main(void)
{
	printf("%d\n", atoi("2147483648099"));
	return (0);
}
