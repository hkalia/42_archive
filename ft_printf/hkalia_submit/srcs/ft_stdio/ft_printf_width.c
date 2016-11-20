/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:33:36 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/17 15:41:09 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <ft_stdlib.h>
#include <stdlib.h>
#include <unistd.h>

#define ATOI(a) ((a) - '0')

int		width_handler_cs(t_printf_parse *parse_state, char **src)
{
	int		src_len;
	int		i;
	char	*tmp;

	src_len = ft_strlen_2(*src);
	if (parse_state->int_width > src_len)
	{
		PRINTF_STR_GRD(!(tmp = ft_calloc(parse_state->int_width + 1,
						sizeof(char))), src, -1);
		ft_memset(tmp, parse_state->flag_zero ? '0' : ' ',
					parse_state->int_width);
		i = -1;
		if (parse_state->flag_minus && src)
			while ((*src)[++i])
				tmp[i] = (*src)[i];
		else if (src)
			while (src && (*src)[++i])
				tmp[parse_state->int_width - src_len--] = (*src)[i];
		free(*src);
		*src = tmp;
		return (0);
	}
	return (0);
}

int		ft_printf_width(char **ret, const char **fmt,
						va_list *ap, t_printf_parse *parse_state)
{
	PRINTF_STR_GRD(parse_state->int_width != 0, ret, -1);
	if (**fmt == '*')
	{
		parse_state->int_width = va_arg(*ap, int);
		++*fmt;
		if (parse_state->int_width < 0)
		{
			parse_state->flag_minus = 1;
			parse_state->int_width = -(parse_state->int_width);
		}
	}
	else
	{
		while (**fmt >= '0' && **fmt <= '9')
		{
			parse_state->int_width = 10 * parse_state->int_width + ATOI(**fmt);
			++*fmt;
		}
	}
	return (0);
}
