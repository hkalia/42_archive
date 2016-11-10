/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:10 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/09 16:31:29 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <ft_string.h>
#include <wchar.h>

int		ft_printf_c(char **ret, const char **fmt,
					va_list *ap, t_printf_parse *parse_state)
{
	char			*tmp;
	unsigned char	src;
//	unsigned char	*src1;

	PRINTF_STR_GRD(parse_state->flag_plus != 0 || parse_state->flag_space != 0
		|| parse_state->flag_hash != 0 || parse_state->flag_zero != 0
		|| parse_state->int_dot != 0
		|| !(parse_state->int_len_mod == 0 || parse_state->int_len_mod == 3)
		, ret, -1);
//	if (parse_state->int_len_mod == 3)
//		src1 = ft_wctomb(va_arg(*ap, wint_t));
//	else
		src = (unsigned char)va_arg(*ap, int);
	if (*ret != 0)
	{
		if (!(*ret = ft_strextend(*ret, 1)))
			return (-1);
	}
	else if (!(*ret = ft_strnew(1)))
		return (-1);
	tmp = *ret;
	tmp += ft_strlen(tmp);
	*tmp = src;
	++*fmt;
	return (1);
}
