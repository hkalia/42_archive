/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:33:36 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/17 16:50:16 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <stdlib.h>
#include <unistd.h>

int8_t	width_handler_csp(t_ft_printf *state, t_arr *new)
{
	char	*tmp;
	int		diff;

	if ((diff = state->int_width - new->len) > 0)
	{
		GRD((tmp = (char *)malloc(sizeof(char) * diff)) == 0, -1);
		ft_memset(tmp, state->flg_zero ? '0' : ' ', diff);
		GRD1(arr_insertat(new, state->flg_minus ? new->len : 0, tmp, diff) == -1
				, free(tmp), -1);
		free(tmp);
		return (0);
	}
	return (0);
}

int8_t	ft_printf_width(t_arr *ret, const char **fmt,
						va_list *ap, t_ft_printf *state)
{
	(void)ret;
	if (**fmt == '*')
	{
		state->int_width = va_arg(*ap, int);
		++*fmt;
		if (state->int_width < 0)
		{
			state->flg_minus = 1;
			state->int_width = -(state->int_width);
		}
	}
	else
	{
		while (**fmt >= '0' && **fmt <= '9')
		{
			state->int_width = 10 * state->int_width + ((**fmt) - '0');
			++*fmt;
		}
	}
	return (0);
}
