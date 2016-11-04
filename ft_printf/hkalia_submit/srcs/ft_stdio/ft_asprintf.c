/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:52:30 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/03 16:00:00 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static char	g_spec[PRINTF_SPEC_LEN][3] = {
	{'%'}, {'-'}, {'+'}, {' '}, {'#'}, {'0'},
	{'*'}, {'1'}, {'2'}, {'3'}, {'4'}, {'5'}, {'6'}, {'7'}, {'8'}, {'9'},
	{'.'},
	{'h', 'h'}, {'h'}, {'l'}, {'l', 'l'}, {'j'}, {'z'},
	{'C'}, {'c'}, {'D'}, {'d'}, {'i'}, {'O'}, {'o'}, {'p'}, {'S'}, {'s'}, {'U'},
	{'u'}, {'X'}, {'x'}};

static t_printf_func_ptr	g_func_arr[PRINTF_SPEC_LEN] = {
	ft_printf_flag_percent, ft_printf_flag_percent, ft_printf_flag_percent,
	ft_printf_flag_percent, ft_printf_flag_percent, ft_printf_flag_percent,
	ft_printf_flag_percent, ft_printf_flag_percent, ft_printf_flag_percent,
	ft_printf_flag_percent, ft_printf_flag_percent, ft_printf_flag_percent,
	ft_printf_flag_percent, ft_printf_flag_percent, ft_printf_flag_percent,
	ft_printf_flag_percent, ft_printf_flag_percent, ft_printf_flag_percent,
	ft_printf_flag_percent, ft_printf_flag_percent, ft_printf_flag_percent,
	ft_printf_flag_percent, ft_printf_flag_percent, ft_printf_flag_percent,
	ft_printf_flag_percent, ft_printf_flag_percent, ft_printf_flag_percent,
	ft_printf_flag_percent, ft_printf_flag_percent, ft_printf_flag_percent,
	ft_printf_flag_percent, ft_printf_flag_percent, ft_printf_flag_percent,
	ft_printf_flag_percent, ft_printf_flag_percent, ft_printf_flag_percent,
	ft_printf_flag_percent};

static int		check(const char *fmt, const char *spec)
{
	int		i;

	i = 0;
	while (spec[i] && fmt[i] == spec[i])
		++i;
	return ((spec[i] == 0 ? 1 : 0));
}

static int		dispatcher(char **ret, const char **fmt, va_list *ap)
{
	t_printf_parse		parse_state;
	int					i;
	int					r;

	PRINTF_STR_GRD(*(++*fmt) == 0, ret, -1);
	i = 0;
	while (i < PRINTF_SPEC_LEN)
	{
		if (check(*fmt, g_spec[i]))
		{
			PRINTF_STR_GRD(
				(r = g_func_arr[i](ret, fmt, ap, &parse_state)) == -1, ret, -1);
			if (r)
				return (1);
		}
		++i;
	}
	ft_strdel(ret);
	return (-1);
}

static int		iterator(char **ret, const char *fmt, va_list *ap)
{
	int		i;
	int		j;

	while (*fmt)
	{
		j = 0;
		while (fmt[j] && fmt[j] != '%')
			++j;
		*ret = ft_strextend(*ret, j);
		i = ft_strlen(*ret);
		while (*fmt && *fmt != '%')
			(*ret)[i++] = *fmt++;
		if (*fmt && *fmt == '%')
			if (dispatcher(ret, &fmt, ap) == -1)
				return (-1);
	}
	return (ft_strlen(*ret));
}

int				ft_asprintf(char **ret, const char *fmt, ...)
{
	va_list	ap;
	int		r;

	if (fmt == 0 || *fmt == 0 || ret == 0)
		return (0);
	*ret = 0;
	if (ft_strchr(fmt, '%') == 0)
		return (((*ret = ft_strdup(fmt)) ? ft_strlen(fmt) : -1));
	va_start(ap, fmt);
	r = iterator(ret, fmt, &ap);
	va_end(ap);
	return (r);
}
