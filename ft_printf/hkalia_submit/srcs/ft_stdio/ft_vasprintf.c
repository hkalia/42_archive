/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:52:30 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/23 11:49:19 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_arr.h>
#include <ft_string.h>
#include <unistd.h>
void	ft_putnbr(int src);
static char	g_spec[FT_PRINTF_LEN1][FT_PRINTF_LEN2] = {
	{'-'}, {'+'}, {' '}, {'#'}
	, {'0'}, {'*'}, {'1'}, {'2'}
	, {'3'}, {'4'}, {'5'}, {'6'}
	, {'7'}, {'8'}, {'9'}, {'.'}
	, {'h', 'h'}, {'h'}, {'l'}, {'l', 'l'}, {'j'}
	, {'z'}, {'d'}, {'i'}, {'o'}, {'u'}
	, {'x'}, {'X'}, {'D'}, {'O'}
	, {'U'}, {'C'}, {'c'}, {'S'}
	, {'s'}, {'p'}, {'%'}};

static int8_t	(*g_funcs[FT_PRINTF_LEN1]) (t_arr *ret, const char **fmt
										, va_list *ap, t_ft_printf *state) = {
	ft_printf_flags, ft_printf_flags, ft_printf_flags, ft_printf_flags
	, ft_printf_flags, ft_printf_width, ft_printf_width, ft_printf_width
	, ft_printf_width, ft_printf_width, ft_printf_width, ft_printf_width
	, ft_printf_width, ft_printf_width, ft_printf_width, ft_printf_dot
	, ft_printf_hh, ft_printf_h, ft_printf_l, ft_printf_ll, ft_printf_j
	, ft_printf_z, ft_printf_d, ft_printf_i, ft_printf_o, ft_printf_u
	, ft_printf_x, ft_printf_cap_x, ft_printf_cap_d, ft_printf_cap_o
	, ft_printf_cap_u, ft_printf_cap_c, ft_printf_c, ft_printf_cap_s
	, ft_printf_s, ft_printf_p, ft_printf_mod};

static bool	check(const char *fmt, char *spec)
{
	size_t	i;

	i = 0;
	while (fmt[i] && spec[i] && fmt[i] == spec[i])
		++i;
	if (spec[i] == 0 && i > 0)
	{
		if (fmt[i - 1] == fmt[i])
			return (0);
		return (1);
	}
	return (0);
}

// int			print_struct(t_ft_printf *state)
// {
// 	if (state->flag_minus)
// 		write(1, "m1\n", 3);
// 	if (state->flag_plus)
// 		write(1, "p1\n", 3);
// 	if (state->flag_space)
// 		write(1, "s1\n", 3);
// 	if (state->flag_hash)
// 		write(1, "h1\n", 3);
// 	if (state->flag_zero)
// 		write(1, "z1\n", 3);
// 	ft_putnbr(state->int_width);
// 	write(1, "\n", 1);
// 	ft_putnbr(state->int_dot);
// 	write(1, "\n", 1);
// 	ft_putnbr(state->int_len_mod);
// 	write(1, "\n", 1);
// 	return (1);
// }

static int8_t	dispatcher(t_arr *ret, const char **fmt, va_list *ap)
{
	t_ft_printf	state;
	size_t		i;
	int8_t		r;

	state = (t_ft_printf){0, 0, 0, 0, 0, 0, 0, 0, 0};
	while (++*fmt)
	{
		i = 0;
		while (i < FT_PRINTF_LEN1)
		{
			if (check(*fmt, g_spec[i]))
			{
				FT_GRD((r = (*g_funcs[i]) (ret, fmt, ap, &state)) == -1, -1);
				if (r > 0)
				{
					//print_struct(&state);
					return (r);
				}
			}
			++i;
		}
	}
	ft_arrreset_f(ret);
	return (-1);
}

static int	iterator(char **final, const char *fmt, va_list *ap)
{
	t_arr	ret;
	size_t	i;

	ret = (t_arr){0, 0, 0};
	FT_GRD(!ft_arrinit(&ret, ft_strlen(fmt)), -1);
	while (*fmt)
	{
		i = 0;
		while (fmt[i] && fmt[i] != '%')
			++i;
		FT_GRD(!ft_arrinsertat(&ret, ret.arr_len, fmt, i), -1);
		fmt += i;
		if (fmt[0] == '%')
		{
			FT_GRD((i = dispatcher(&ret, &fmt, ap)) == -1, -1);
			if (i == 2)
				break ;
		}
	}
	FT_GRD1(!(*final = ft_arrtostr(&ret)), free(ret.arr), -1);
	return (ret.arr_len);
}

int			ft_vasprintf(char **ret, const char *fmt, va_list *ap)
{
	int		r;

	if (fmt == 0 || *fmt == 0 || ret == 0)
		return (0);
	*ret = 0;
	if (ft_strchr(fmt, '%') == 0)
		return (((*ret = ft_strdup(fmt)) ? ft_strlen(fmt) : -1));
	r = iterator(ret, fmt, ap);
	return (r);
}
