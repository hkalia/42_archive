/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:44 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/09 13:08:45 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <ft_string.h>

int		ft_printf_i(char **ret, const char **fmt,
					va_list *ap, t_printf_parse *parse_state)
{
	char	*new;

	(void)ap;
	(void)parse_state;
	if (*ret != 0)
	{
		PRINTF_STR_GRD(!(new = ft_strjoin(*ret, "i")), ret, -1);
	}
	else
		PRINTF_STR_GRD(!(new = ft_strdup("i")), ret, -1);
	ft_strdel(ret);
	*ret = new;
	++*fmt;
	return (1);
}
