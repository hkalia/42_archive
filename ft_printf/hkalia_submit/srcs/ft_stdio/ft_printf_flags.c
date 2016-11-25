/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:34:41 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/24 14:38:50 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>

int8_t	ft_printf_flags(t_arr *ret, const char **fmt,
						va_list *ap, t_ft_printf *state)
{
	(void)ret;
	(void)ap;
	while (**fmt && (**fmt == '-' || **fmt == '+' || **fmt == ' '
			|| **fmt == '#' || **fmt == '0'))
	{
		if (**fmt == '-')
		{
			state->flag_zero = 0;
			state->flag_minus = 1;
		}
		else if (**fmt == '+')
		{
			state->flag_space = 0;
			state->flag_plus = 1;
		}
		else if (**fmt == ' ' && !state->flag_plus)
			state->flag_space = 1;
		else if (**fmt == '#')
			state->flag_hash = 1;
		else if (**fmt == '0' && !state->flag_minus)
			state->flag_zero = 1;
		++*fmt;
	}
	return (0);
}
