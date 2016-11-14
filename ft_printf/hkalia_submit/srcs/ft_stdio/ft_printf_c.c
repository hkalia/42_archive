/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:10 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/13 18:21:30 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <ft_string.h>
#include <ft_stdlib.h>
#include <wchar.h>
#include <stdlib.h>

int		ft_printf_c(char **ret, const char **fmt,
					va_list *ap, t_printf_parse *parse_state)
{
	wint_t			tmp1;
	unsigned char	tmp2;
	char			*new;
	char			*tmp;

	PRINTF_STR_GRD(parse_state->flag_plus || parse_state->flag_space
		|| parse_state->flag_hash || parse_state->flag_zero
		|| parse_state->flag_dot != 0
		|| !(parse_state->int_len_mod == 0 || parse_state->int_len_mod == 3)
		, ret, -1);
	if (parse_state->int_len_mod == 3)
	{
		PRINTF_STR_GRD(!(new = ft_calloc(5, sizeof(char))), ret, -1);
		PRINTF_STR_GRD(!(tmp1 = va_arg(*ap, wint_t)), ret, -1);
		if(ft_wctomb(new, tmp1) == -1)
		{
			ft_strdel(&new);
			ft_strdel(ret);
			return (-1);
		}
	}
	else
	{
		PRINTF_STR_GRD(!(new = ft_calloc(2, sizeof(char))), ret, -1);
		PRINTF_STR_GRD(!(tmp2 = (unsigned char)va_arg(*ap, int)), ret, -1);
		new[0] = tmp2;
	}
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
