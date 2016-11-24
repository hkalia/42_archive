/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:51 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/23 12:53:12 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <ft_string.h>
#include <wchar.h>

// static int	dot_handler(t_ft_printf *state, char **src)
// {
// 	int		i;
// 	char	*tmp;
//
// 	if (state->flag_dot && src)
// 	{
// 		PRINTF_STR_GRD(state->int_dot == 0, src, 0);
// 		PRINTF_STR_GRD(!(tmp = ft_calloc(state->int_dot + 1,
// 			sizeof(char))), src, -1);
// 		i = 0;
// 		while (state->int_dot--)
// 		{
// 			tmp[i] = (*src)[i];
// 			++i;
// 		}
// 		free(*src);
// 		*src = tmp;
// 		return (0);
// 	}
// 	return (0);
// }

static int8_t	ft_printf_s_l(va_list *ap, char **new)
{
	wchar_t	*tmp;

	tmp = va_arg(*ap, wchar_t *);
	FT_GRD(ft_wcstombs(new, tmp) == -1, -1);
	return (1);
}

int8_t			ft_printf_s(t_arr *ret, const char **fmt,
						va_list *ap, t_ft_printf *state)
{
	char	*new;
	char	*tmp;

	if (state->int_len_mod == 3)
	{
		FT_GRD1(ft_printf_s_l(ap, &new) == -1, free(ret->arr), -1);
	}
	else
	{
		tmp = va_arg(*ap, char *);
		FT_GRD1(!(new = ft_strdup(tmp)), free(ret->arr), -1);
	}
	FT_GRD2(!ft_arrinsertat(ret, ret->arr_len, new, ft_strlen(new)), free(new)
			, free(ret->arr), -1);
	free(new);
	++*fmt;
	return (1);
}
