/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:34:41 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/28 14:35:46 by hkalia           ###   ########.fr       */
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
			state->flg_zero = 0;
			state->flg_minus = 1;
		}
		else if (**fmt == '+')
		{
			state->flg_space = 0;
			state->flg_plus = 1;
		}
		else if (**fmt == ' ' && !state->flg_plus)
			state->flg_space = 1;
		else if (**fmt == '#')
			state->flg_hash = 1;
		else if (**fmt == '0' && !state->flg_minus)
			state->flg_zero = 1;
		++*fmt;
	}
	return (0);
}
