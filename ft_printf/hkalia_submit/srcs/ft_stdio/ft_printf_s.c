/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:51 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/17 17:42:23 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <ft_string.h>
#include <ft_stdlib.h>
#include <wchar.h>
#include <stdlib.h>

static int	dot_handler(t_printf_parse *parse_state, char **src)
{
	int		i;
	char	*tmp;

	if (parse_state->flag_dot && src)
	{
		PRINTF_STR_GRD(parse_state->int_dot == 0, src, 0);
		PRINTF_STR_GRD(!(tmp = ft_calloc(parse_state->int_dot + 1,
			sizeof(char))), src, -1);
		i = 0;
		while (parse_state->int_dot--)
		{
			tmp[i] = (*src)[i];
			++i;
		}
		free(*src);
		*src = tmp;
		return (0);
	}
	return (0);
}

static int	ft_printf_s_l(va_list *ap, char **new)
{
	wchar_t	*tmp;

	tmp = va_arg(*ap, wchar_t *);
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
		tmp = va_arg(*ap, char *);
		PRINTF_STR_GRD(!(new = ft_strdup(tmp)), ret, -1);
	}
	PRINTF_STR_GRD(dot_handler(parse_state, &new) == -1, ret, -1);
	PRINTF_STR_GRD(width_handler_cs(parse_state, &new) == -1, ret, -1);
	if (*new == 0 && !parse_state->flag_dot)
		new = ft_strdup("(null)");
	PRINTF_STR_GRD2(!(*ret = ft_strjoin_2(*ret, new)), 2, -1, ret, &new);
	++*fmt;
	return (1);
}
