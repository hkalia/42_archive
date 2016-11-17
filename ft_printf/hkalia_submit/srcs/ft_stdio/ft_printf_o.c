/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:47 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/16 17:34:03 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <stdlib.h>

int		ft_printf_o(char **ret, const char **fmt,
					va_list *ap, t_printf_parse *parse_state)
{
	char				*new;
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
	PRINTF_STR_GRD(!(new = ft_itoa_base(tmp, 8, "01234567")), ret, -1);
	PRINTF_STR_GRD(width_handler_s(parse_state, &new) == -1, ret, -1);
	PRINTF_STR_GRD2(!(*ret = ft_strjoin_2(*ret, new)), 2, -1, ret, &new);
	++*fmt;
	return (1);
}
