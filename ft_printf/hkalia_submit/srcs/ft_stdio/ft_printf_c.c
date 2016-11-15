/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:10 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/14 14:45:17 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <ft_string.h>
#include <ft_stdlib.h>
#include <wchar.h>
#include <stdlib.h>

static int	ft_printf_c_l(va_list *ap, char **new)
{
	wint_t	tmp;

	PRINTF_STR_GRD(!(*new = ft_calloc(5, sizeof(char))), 0, -1);
	PRINTF_STR_GRD(!(tmp = va_arg(*ap, wint_t)), new, -1);
	PRINTF_STR_GRD(ft_wctomb(*new, tmp) == -1, new, -1);
	return (1);
}

int			ft_printf_c(char **ret, const char **fmt,
					va_list *ap, t_printf_parse *parse_state)
{
	unsigned char	tmp;
	char			*new;

	PRINTF_STR_GRD(parse_state->flag_plus || parse_state->flag_space
		|| parse_state->flag_hash || parse_state->flag_zero
		|| parse_state->flag_dot != 0
		|| !(parse_state->int_len_mod == 0 || parse_state->int_len_mod == 3)
		, ret, -1);
	if (parse_state->int_len_mod == 3)
	{
		PRINTF_STR_GRD(ft_printf_c_l(ap, &new) == -1, ret, -1);
	}
	else
	{
		PRINTF_STR_GRD(!(new = ft_calloc(2, sizeof(char))), ret, -1);
		PRINTF_STR_GRD(!(tmp = (unsigned char)va_arg(*ap, int)), ret, -1);
		new[0] = tmp;
	}
	PRINTF_STR_GRD(width_handler(parse_state, &new) == -1, ret, -1);
	PRINTF_STR_GRD2(!(*ret = ft_strjoin_2(*ret, new)), 2, -1, ret, &new);
	++*fmt;
	return (1);
}
