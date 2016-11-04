/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_percent.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:40:01 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/03 15:40:47 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>

int		ft_printf_flag_percent(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state)
{
	char	*new;

	PRINTF_STR_GRD(!(new = ft_strjoin(*ret, "%")), ret, -1);
	ft_strdel(ret);
	*ret = new;
	++*fmt;
	(void)ap;
	(void)parse_state;
	return (1);
}
