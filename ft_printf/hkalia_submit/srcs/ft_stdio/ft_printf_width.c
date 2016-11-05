/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:33:36 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/04 17:26:28 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_stdlib.h>
#include <stdlib.h>

int		ft_printf_width(char **ret, const char **fmt,
	va_list *ap, t_printf_parse *parse_state)
{
	char	*n;
	int		i;

	if (**fmt == '*')
		parse_state->flag_min_field_width = va_arg(*ap, int);
	else
	{
		PRINTF_STR_GRD(!(n = ft_strnew(10)), ret, -1);
		i = 0;
		while (**fmt >= '1' && **fmt <= '9' && i < 10)
		{
			n[i] = **fmt;
			++i;
			++*fmt;
		}
		parse_state->flag_min_field_width = ft_atoi(n);
		free(n);
	}
	if (parse_state->flag_min_field_width < 0)
		return (-1);
	return (0);
}
