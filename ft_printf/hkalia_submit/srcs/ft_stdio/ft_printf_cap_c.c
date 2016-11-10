/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cap_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:20 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/09 15:51:17 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <ft_string.h>

int		ft_printf_cap_c(char **ret, const char **fmt,
						va_list *ap, t_printf_parse *parse_state)
{
	char			*tmp;
	unsigned char	src;

	PRINTF_STR_GRD(parse_state->flag_plus != 0, ret, -1);
	src = (unsigned char)va_arg(*ap, int);
	if (*ret != 0)
	{
		if (!(*ret = ft_strextend(*ret, 1)))
			return (-1);
	}
	else if (!(*ret = ft_strnew(1)))
		return (-1);
	tmp = *ret;
	tmp += ft_strlen(tmp);
	*tmp = src;
	++*fmt;
	return (1);
}
