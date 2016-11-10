/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_j.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:11:13 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/08 14:45:49 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>

int		ft_printf_j(char **ret, const char **fmt,
					va_list *ap, t_printf_parse *parse_state)
{
	(void)fmt;
	(void)ap;
	PRINTF_STR_GRD(parse_state->int_len_mod != 0, ret, -1);
	parse_state->int_len_mod = 5;
	++*fmt;
	return (0);
}
