/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:51 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/16 14:26:14 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <ft_string.h>
#include <ft_stdlib.h>
#include <wchar.h>
#include <stdlib.h>

static int	ft_printf_s_l(va_list *ap, char **new)
{
	wchar_t	*tmp;

	PRINTF_STR_GRD(!(tmp = va_arg(*ap, wchar_t *)), 0, -1);
	PRINTF_STR_GRD(ft_wcstombs(new, tmp) == -1, 0, -1);
	return (1);
}

int			ft_printf_s(char **ret, const char **fmt,
					va_list *ap, t_printf_parse *parse_state)
{
	char	*new;
	char	*tmp;

	if (parse_state->int_len_mod == 3)
	{
		PRINTF_STR_GRD(ft_printf_s_l(ap, &new) == -1, ret, -1);
	}
	else
	{
		PRINTF_STR_GRD(!(tmp = va_arg(*ap, char *)), ret, -1);
		PRINTF_STR_GRD(!(new = ft_strdup(tmp)), ret, -1);
	}
	PRINTF_STR_GRD(dot_handler_s(parse_state, &new) == -1, ret, -1);
	PRINTF_STR_GRD(width_handler_s(parse_state, &new) == -1, ret, -1);
	PRINTF_STR_GRD2(!(*ret = ft_strjoin_2(*ret, new)), 2, -1, ret, &new);
	++*fmt;
	return (1);
}
