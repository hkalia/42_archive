/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 18:05:17 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/31 18:34:25 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct	s_printf_store
{
	bool	flag_minus;
	bool	flag_plus;
	bool	flag_space;
	bool	flag_hash;
	bool	flag_zero;
	int		flag_min_field_width;
	int		flag_precision;
	int		flag_len_mod;
}				t_printf_store;

int		main(void)
{
	t_printf_store storage;

	storage = (t_printf_store){.flag_minus = false, .flag_plus = false};
	printf("%d %d\n", storage.flag_minus, storage.flag_plus);
	return (0);
}
