/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:51 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/13 11:27:32 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <ft_string.h>
#include <ft_stdlib.h>
#include <wchar.h>

int		ft_printf_s(char **ret, const char **fmt,
					va_list *ap, t_printf_parse *parse_state)
{
	char	*src;

	(void)ap;
	PRINTF_STR_GRD(parse_state->flag_zero || parse_state->flag_plus
		|| parse_state->flag_space || parse_state->flag_hash
		|| !(parse_state->int_len_mod == 0 || parse_state->int_len_mod == 3)
		, ret, -1);
	if (parse_state->int_len_mod == 3)
	{
		PRINTF_STR_GRD(ft_wcstombs(&src, va_arg(*ap, wchar_t *)) == -1
			, ret, -1);
	}
	else
		src = va_arg(*ap, char *);
	PRINTF_STR_GRD(!(*ret = ft_strextend(*ret, ft_strlen_2(src))), &src, -1);
	ft_strcat(*ret, src);
	PRINTF_STR_GRD((width_handler(ret, parse_state, src) == -1), &src, -1);
	++*fmt;
	return (1);
}
