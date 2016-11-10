/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:47 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/09 13:08:27 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <ft_string.h>

int		ft_printf_o(char **ret, const char **fmt,
					va_list *ap, t_printf_parse *parse_state)
{
	char	*new;

	(void)ap;
	(void)parse_state;
	if (*ret != 0)
	{
		PRINTF_STR_GRD(!(new = ft_strjoin(*ret, "o")), ret, -1);
	}
	else
		PRINTF_STR_GRD(!(new = ft_strdup("o")), ret, -1);
	ft_strdel(ret);
	*ret = new;
	++*fmt;
	return (1);
}
