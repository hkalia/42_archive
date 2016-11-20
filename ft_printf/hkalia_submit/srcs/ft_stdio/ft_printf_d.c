/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:41 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/17 15:57:06 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <stdlib.h>

int		ft_printf_d(char **ret, const char **fmt,
					va_list *ap, t_printf_parse *parse_state)
{
	char		*new;
	intmax_t	tmp;

	tmp = va_arg(*ap, intmax_t);
	if (parse_state->int_len_mod == 0)
		tmp = (int)tmp;
	else if (parse_state->int_len_mod == 1)
		tmp = (signed char)tmp;
	else if (parse_state->int_len_mod == 2)
		tmp = (short)tmp;
	else if (parse_state->int_len_mod == 3)
		tmp = (long)tmp;
	else if (parse_state->int_len_mod == 4)
		tmp = (long long)tmp;
	PRINTF_STR_GRD(!(new = ft_itoa(tmp)), ret, -1);
	PRINTF_STR_GRD(flag_handler_doxu(parse_state, &new) == -1, ret, -1);
	PRINTF_STR_GRD2(!(*ret = ft_strjoin_2(*ret, new)), 2, -1, ret, &new);
	++*fmt;
	return (1);
}
