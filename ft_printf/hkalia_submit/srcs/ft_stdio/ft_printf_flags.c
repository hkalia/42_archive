/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:34:41 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/17 10:44:19 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>

int		ft_printf_flags(char **ret, const char **fmt,
						va_list *ap, t_printf_parse *parse_state)
{
	(void)ret;
	(void)ap;
	while (**fmt && (**fmt == '-' || **fmt == '+' || **fmt == ' '
			|| **fmt == '#' || **fmt == '0'))
	{
		if (**fmt == '-')
		{
			parse_state->flag_zero = 0;
			parse_state->flag_minus = 1;
		}
		else if (**fmt == '+')
		{
			parse_state->flag_space = 0;
			parse_state->flag_plus = 1;
		}
		else if (**fmt == ' ')
		{
			if (parse_state->flag_plus)
				parse_state->flag_space = 0;
			else
				parse_state->flag_space = 1;
		}
		else if (**fmt == '#')
			parse_state->flag_hash = 1;
		else if (**fmt == '0')
			parse_state->flag_zero = 1;
		++*fmt;
	}
	return (0);
}
