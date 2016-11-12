/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:10 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/11 17:15:28 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <ft_string.h>
#include <ft_stdlib.h>
#include <wchar.h>
#include <stdlib.h>

int		ft_printf_c(char **ret, const char **fmt,
					va_list *ap, t_printf_parse *parse_state)
{
	char	*src;

	PRINTF_STR_GRD(parse_state->flag_plus || parse_state->flag_space
		|| parse_state->flag_hash || parse_state->flag_zero
		|| parse_state->int_dot != 0
		|| !(parse_state->int_len_mod == 0 || parse_state->int_len_mod == 3)
		, ret, -1);
	if (parse_state->int_len_mod == 3)
	{
		PRINTF_STR_GRD(!(src = (char *)ft_wctomb(va_arg(*ap, wint_t))),
						ret, -1);
	}
	else
	{
		PRINTF_STR_GRD(!(src = ft_calloc(2, sizeof(unsigned char))), ret, -1);
		src[0] = (unsigned char)va_arg(*ap, int);
	}
	PRINTF_STR_GRD(!(*ret = ft_strextend(*ret, ft_strlen(src))), &src, -1)
	ft_strcat(*ret, src);
	PRINTF_STR_GRD(width_handler(ret, parse_state, src) == -1, &src, -1);
	free(src);
	++*fmt;
	return (1);
}
