/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:53:00 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/10 16:04:58 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <stdbool.h>
# include <stdarg.h>
# include "ft_custom.h"

/*
**	if you add stuff to this struct, make sure to go to the dispatcher function
**	and initialize it to it's default value.
*/

typedef struct	s_printf_parse
{
	bool		flag_minus;
	bool		flag_plus;
	bool		flag_space;
	bool		flag_hash;
	bool		flag_zero;
	int			int_width;
	int			int_dot;
	int			int_len_mod;
}				t_printf_parse;
typedef int	(*t_printf_func_ptr)(char **ret, const char **fmt,\
								va_list *ap, t_printf_parse *parse_state);

# define PRINTF_STR_GRD(a, b, c) if (a) {ft_strdel(b); return (c);}
# define PRINTF_SPEC_LEN 37

int				ft_putchar(int src);
int				ft_printf(const char *fmt, ...);
int				ft_vasprintf(char **ret, const char *fmt, va_list *ap);

/*
**	PART OF PRINTF
*/

int				ft_printf_flags(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_width(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_dot(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_hh(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_h(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_l(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_ll(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_j(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_z(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_mod(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_cap_c(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_c(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_cap_d(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_d(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_i(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_cap_o(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_o(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_p(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_cap_s(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_s(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_cap_u(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_u(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_cap_x(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_x(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);

#endif
