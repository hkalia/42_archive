/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:50:33 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/14 15:30:08 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_stdlib.h>
#include <stdlib.h>

#define ATOI(a) ((a) - '0')

int		dot_handler(t_printf_parse *parse_state, char **src)
{
	int		i;
	char	*tmp;

	if (src == 0 || *src == 0)
		return (-1);
	if (parse_state->flag_dot)
	{
		PRINTF_STR_GRD(parse_state->int_dot == 0, src, -1);
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

int		ft_printf_dot(char **ret, const char **fmt,
						va_list *ap, t_printf_parse *parse_state)
{
	(void)ret;
	++*fmt;
	parse_state->flag_dot = 1;
	if (**fmt == '*')
	{
		parse_state->int_dot = va_arg(*ap, int);
		++*fmt;
		if (parse_state->int_dot < 0)
			parse_state->int_dot = 0;
	}
	else
	{
		while (**fmt >= '0' && **fmt <= '9')
		{
			parse_state->int_dot = 10 * parse_state->int_dot + ATOI(**fmt);
			++*fmt;
		}
	}
	return (0);
}
