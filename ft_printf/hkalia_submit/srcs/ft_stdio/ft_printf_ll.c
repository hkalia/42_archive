/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:13:57 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/08 16:00:55 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>

int		ft_printf_ll(char **ret, const char **fmt,
						va_list *ap, t_printf_parse *parse_state)
{
	(void)fmt;
	(void)ap;
	PRINTF_STR_GRD(parse_state->int_len_mod != 0, ret, -1);
	parse_state->int_len_mod = 4;
	*fmt += 2;
	return (0);
}
