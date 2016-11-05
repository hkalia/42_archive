/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:50:33 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/05 15:04:49 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>

#define ATOI(a) ((a) - '0')

int				ft_printf_dot(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state)
{
	(void)ret;
	++*fmt;
	if (**fmt == '*')
	{
		parse_state->int_dot = va_arg(*ap, int);
		++*fmt;
		if (parse_state->int_dot < 0)
			parse_state->int_dot = 0;
	}
	else
	{
		while(**fmt >= '0' && **fmt <= '9')
		{
			parse_state->int_dot = 10 * parse_state->int_dot + ATOI(**fmt);
			++*fmt;
		}
	}
	return (0);
}
