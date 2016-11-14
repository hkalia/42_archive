/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:51 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/13 18:22:21 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <ft_string.h>
#include <ft_stdlib.h>
#include <wchar.h>
#include <stdlib.h>

int		ft_printf_s(char **ret, const char **fmt,
					va_list *ap, t_printf_parse *parse_state)
{
	char	*new;
	char	*tmp;

	(void)ap;
	PRINTF_STR_GRD(!(new = ft_calloc(2, sizeof(char))), ret, -1);
	new[0] = 's';
	PRINTF_STR_GRD(width_handler(parse_state, &new) == -1, ret, -1);
	tmp = *ret;
	if (!(*ret = ft_strjoin(*ret, new)))
	{
		ft_strdel(&new);
		ft_strdel(ret);
		return (-1);
	}
	free(new);
	free(tmp);
	++*fmt;
	return (1);
}
