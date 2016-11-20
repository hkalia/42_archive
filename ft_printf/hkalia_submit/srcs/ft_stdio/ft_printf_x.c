/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:56 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/17 17:36:18 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <ft_string.h>
#include <ft_stdlib.h>

int		ft_printf_x(char **ret, const char **fmt,
					va_list *ap, t_printf_parse *parse_state)
{
	char				*new;
	char				*tmp1;
	uintmax_t			tmp;

	tmp = va_arg(*ap, uintmax_t);
	if (parse_state->int_len_mod == 0)
		tmp = (unsigned int)tmp;
	else if (parse_state->int_len_mod == 1)
		tmp = (unsigned char)tmp;
	else if (parse_state->int_len_mod == 2)
		tmp = (unsigned short)tmp;
	else if (parse_state->int_len_mod == 3)
		tmp = (unsigned long)tmp;
	else if (parse_state->int_len_mod == 4)
		tmp = (unsigned long long)tmp;
	PRINTF_STR_GRD(!(new = ft_itoa_base(tmp, 16, "0123456789abcdef")), ret, -1);
	PRINTF_STR_GRD(flag_handler_doxu(parse_state, &new) == -1, ret, -1);
	PRINTF_STR_GRD(width_handler_cs(parse_state, &new) == -1, ret, -1);
	if (parse_state->flag_hash)
	{
		PRINTF_STR_GRD(!(tmp1 = ft_calloc(3, sizeof(char))), ret, -1);
		tmp1[0] = '0';
		tmp1[1] = 'x';
		PRINTF_STR_GRD(!(new = ft_strpush(new, tmp1)), ret, -1);
	}
	PRINTF_STR_GRD2(!(*ret = ft_strjoin_2(*ret, new)), 2, -1, ret, &new);
	++*fmt;
	return (1);
}
