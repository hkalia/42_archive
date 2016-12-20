/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:34:41 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/18 15:59:08 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>

int8_t	ft_printf_flags(t_ft_printf *s)
{
	while (*s->fmt && (*s->fmt == '-' || *s->fmt == '+' || *s->fmt == ' '
			|| *s->fmt == '#' || *s->fmt == '0'))
	{
		if (*s->fmt == '-')
		{
			s->flg_zero = 0;
			s->flg_minus = 1;
		}
		else if (*s->fmt == '+')
		{
			s->flg_space = 0;
			s->flg_plus = 1;
		}
		else if (*s->fmt == ' ' && !s->flg_plus)
			s->flg_space = 1;
		else if (*s->fmt == '#')
			s->flg_hash = 1;
		else if (*s->fmt == '0' && !s->flg_minus)
			s->flg_zero = 1;
		++s->fmt;
	}
	return (0);
}
