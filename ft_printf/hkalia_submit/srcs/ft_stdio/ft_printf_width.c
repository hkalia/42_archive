/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:33:36 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/23 11:25:30 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <ft_stdlib.h>
#include <unistd.h>

// int		width_handler_cs(t_ft_printf *state, char **src)
// {
// 	int		src_len;
// 	int		i;
// 	char	*tmp;
//
// 	src_len = ft_strlen_2(*src);
// 	if (state->int_width > src_len)
// 	{
// 		PRINTF_STR_GRD(!(tmp = ft_calloc(state->int_width + 1,
// 						sizeof(char))), src, -1);
// 		ft_memset(tmp, state->flag_zero ? '0' : ' ',
// 					state->int_width);
// 		i = -1;
// 		if (state->flag_minus && src)
// 			while ((*src)[++i])
// 				tmp[i] = (*src)[i];
// 		else if (src)
// 			while (src && (*src)[++i])
// 				tmp[state->int_width - src_len--] = (*src)[i];
// 		free(*src);
// 		*src = tmp;
// 		return (0);
// 	}
// 	return (0);
// }

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
			state->flag_minus = 1;
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
