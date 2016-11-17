/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:54 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/16 16:25:34 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <ft_string.h>

int		ft_printf_u(char **ret, const char **fmt,
					va_list *ap, t_printf_parse *parse_state)
{
	char				*new;
	uintmax_t			tmp;

	tmp = va_arg(*ap, uintmax_t);
	PRINTF_STR_GRD(!(new = ft_itoa_base(tmp, 10, "0123456789")), ret, -1);
	PRINTF_STR_GRD(width_handler_s(parse_state, &new) == -1, ret, -1);
	PRINTF_STR_GRD2(!(*ret = ft_strjoin_2(*ret, new)), 2, -1, ret, &new);
	++*fmt;
	return (1);
}
