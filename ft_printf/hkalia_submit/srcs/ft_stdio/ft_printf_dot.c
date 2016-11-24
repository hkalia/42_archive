/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:50:33 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/23 11:25:30 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <ft_stdlib.h>

// int			flag_handler_doxu(t_ft_printf *state, char **src)
// {
// 	int		src_len;
// 	bool	flg_neg;
// 	char	*tmp;
//
// 	flg_neg = **src == '-' ? 1 : 0;
// 	if (state->flag_dot)
// 	{
// 		src_len = 0;
// 		while ((*src)[src_len])
// 			++src_len;
// 		src_len = flg_neg ? src_len - 1 : src_len;
// 		if (state->int_dot > src_len)
// 		{
// 			PRINTF_STR_GRD(!(tmp = ft_calloc(state->int_dot - src_len + 1,
// 							sizeof(char))), src, -1);
// 			ft_memset(tmp, '0', state->int_dot - src_len);
// 			PRINTF_STR_GRD(!(*src = ft_strpush(*src, tmp)), 0, -1);
// 			if ((tmp = ft_strchr(*src, '-')) != 0)
// 			{
// 				*tmp = '0';
// 				(*src)[0] = '-';
// 			}
// 		}
// 	}
// 	if (state->flag_plus && !flg_neg)
// 	{
// 		PRINTF_STR_GRD(!(tmp = ft_calloc(2, sizeof(char))), src, -1);
// 		tmp[0] = '+';
// 		PRINTF_STR_GRD(!(*src = ft_strpush(*src, tmp)), 0, -1);
// 	}
// 	if (state->flag_space && !flg_neg)
// 	{
// 		PRINTF_STR_GRD(!(tmp = ft_calloc(2, sizeof(char))), src, -1);
// 		tmp[0] = ' ';
// 		PRINTF_STR_GRD(!(*src = ft_strpush(*src, tmp)), 0, -1);
// 	}
// 	return (0);
// }

int8_t	ft_printf_dot(t_arr *ret, const char **fmt,
						va_list *ap, t_ft_printf *state)
{
	(void)ret;
	++*fmt;
	state->flag_dot = 1;
	if (**fmt == '*')
	{
		state->int_dot = va_arg(*ap, int);
		++*fmt;
		if (state->int_dot < 0)
		{
			state->int_dot = 0;
			state->flag_dot = 0;
		}
	}
	else
	{
		while (**fmt >= '0' && **fmt <= '9')
		{
			state->int_dot = 10 * state->int_dot + ((**fmt) - '0');
			++*fmt;
		}
	}
	return (0);
}
