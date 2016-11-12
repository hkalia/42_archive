/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:33:36 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/11 17:16:00 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>

#define ATOI(a) ((a) - '0')

int		width_handler(char **ret, t_printf_parse *parse_state, const char *src)
{
	int		src_len;
	char	*tmp;

	src_len = ft_strlen_2(src);
	if (parse_state->int_width > src_len)
	{
		if (!(*ret = ft_strextend(*ret, parse_state->int_width - src_len)))
			return (-1);
		tmp = *ret;
		tmp += ft_strlen(tmp);
		if (parse_state->flag_minus)
			while (parse_state->int_width-- - src_len)
				*tmp++ = ' ';
		else
		{
			tmp = tmp - src_len;
			while (parse_state->int_width-- - src_len)
				*tmp++ = ' ';
			ft_strcat(*ret, src);
		}
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
