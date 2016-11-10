/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:52:30 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/09 14:32:00 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static char	g_spec[PRINTF_SPEC_LEN][3] = {
	{'-'}, {'+'}, {' '}, {'#'}, {'0'},
	{'*'}, {'1'}, {'2'}, {'3'}, {'4'}, {'5'}, {'6'}, {'7'}, {'8'}, {'9'},
	{'.'},
	{'h', 'h'}, {'h'}, {'l'}, {'l', 'l'}, {'j'}, {'z'},
	{'%'},
	{'C'}, {'c'}, {'D'}, {'d'}, {'i'}, {'O'}, {'o'}, {'p'}, {'S'}, {'s'}, {'U'},
	{'u'}, {'X'}, {'x'}};

static t_printf_func_ptr	g_func_arr[PRINTF_SPEC_LEN] = {
	[0 ... 4] = ft_printf_flags,
	[5 ... 14] = ft_printf_width,
	ft_printf_dot, ft_printf_hh, ft_printf_h, ft_printf_l, ft_printf_ll,
	ft_printf_j, ft_printf_z, ft_printf_mod, ft_printf_cap_c, ft_printf_c,
	ft_printf_cap_d, ft_printf_d, ft_printf_i, ft_printf_cap_o, ft_printf_o,
	ft_printf_p, ft_printf_cap_s, ft_printf_s, ft_printf_cap_u, ft_printf_u,
	ft_printf_cap_x, ft_printf_x};

static int		check(const char *cur, int i)
{
	int		j;

	j = 0;
	while (g_spec[i][j] && *(cur + j) == g_spec[i][j])
		++j;
	if (*(cur + j) == *cur)
		return (0);
	return ((g_spec[i][j] == 0 ? 1 : 0));
}

void			print_struct(t_printf_parse *parse_state)
{
	if (parse_state->flag_minus)
		write(1, "m1\n", 3);
	if (parse_state->flag_plus)
		write(1, "p1\n", 3);
	if (parse_state->flag_space)
		write(1, "s1\n", 3);
	if (parse_state->flag_hash)
		write(1, "h1\n", 3);
	if (parse_state->flag_zero)
		write(1, "z1\n", 3);
	ft_putnbr(parse_state->int_width);
	write(1, "\n", 1);
	ft_putnbr(parse_state->int_dot);
	write(1, "\n", 1);
	ft_putnbr(parse_state->int_len_mod);
	write(1, "\n", 1);
}

static int		dispatcher(char **ret, const char **fmt, va_list *ap)
{
	t_printf_parse	parse_state;
	int				i;
	int				r;

	PRINTF_STR_GRD(*(++*fmt) == 0, ret, -1);
	parse_state = (t_printf_parse){0, 0, 0, 0, 0, 0, 0, 0};
	i = 0;
	while (i < PRINTF_SPEC_LEN)
	{
		if (check(*fmt, i))
		{
			if ((r = g_func_arr[i](ret, fmt, ap, &parse_state)) == -1)
				return (-1);
			if (r)
			{
				print_struct(&parse_state);
				return (1);
			}
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
		if (j)
			if (!(*ret = ft_strextend(*ret, j)))
				return (-1);
		i = ft_strlen_2(*ret);
		if (*ret != 0)
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
