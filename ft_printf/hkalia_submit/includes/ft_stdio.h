/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:53:00 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/26 17:21:55 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <stdbool.h>
# include <stdarg.h>
# include <stdlib.h>
# include "ft_arr.h"

/*
**	if you add stuff to this struct, make sure to go to the dispatcher function
**	and initialize it to it's default value.
*/

typedef struct	s_ft_printf
{
	bool		flag_minus;
	bool		flag_plus;
	bool		flag_space;
	bool		flag_hash;
	bool		flag_zero;
	int			int_width;
	bool		flag_dot;
	int			int_dot;
	int			int_len_mod;
}				t_ft_printf;

# ifndef FT_GRD
#  define FT_GRD(a, b) if (a) {return(b);}
# endif

# ifndef FT_GRD1
#  define FT_GRD1(a, b, c) if (a) {b; return(c);}
# endif

# ifndef FT_GRD2
#  define FT_GRD2(a, b, c, d) if (a) {b; c; return(d);}
# endif

# define FT_PRINTF_LEN1 37
# define FT_PRINTF_LEN2	3

int				ft_putchar(int src);
int				ft_printf(const char *fmt, ...);
int				ft_vasprintf(char **ret, const char *fmt, va_list *ap);

/*
**	PART OF PRINTF
*/

int8_t			ft_printf_flags(t_arr *ret, const char **fmt,
								va_list *ap, t_ft_printf *state);
int8_t			ft_printf_width(t_arr *ret, const char **fmt,
								va_list *ap, t_ft_printf *state);
int8_t			ft_printf_dot(t_arr *ret, const char **fmt,
								va_list *ap, t_ft_printf *state);
int8_t			ft_printf_hh(t_arr *ret, const char **fmt,
								va_list *ap, t_ft_printf *state);
int8_t			ft_printf_h(t_arr *ret, const char **fmt,
							va_list *ap, t_ft_printf *state);
int8_t			ft_printf_l(t_arr *ret, const char **fmt,
							va_list *ap, t_ft_printf *state);
int8_t			ft_printf_ll(t_arr *ret, const char **fmt,
								va_list *ap, t_ft_printf *state);
int8_t			ft_printf_j(t_arr *ret, const char **fmt,
							va_list *ap, t_ft_printf *state);
int8_t			ft_printf_z(t_arr *ret, const char **fmt,
							va_list *ap, t_ft_printf *state);
int8_t			ft_printf_d(t_arr *ret, const char **fmt,
							va_list *ap, t_ft_printf *state);
int8_t			ft_printf_i(t_arr *ret, const char **fmt,
							va_list *ap, t_ft_printf *state);
int8_t			ft_printf_o(t_arr *ret, const char **fmt,
							va_list *ap, t_ft_printf *state);
int8_t			ft_printf_u(t_arr *ret, const char **fmt,
							va_list *ap, t_ft_printf *state);
int8_t			ft_printf_x(t_arr *ret, const char **fmt,
							va_list *ap, t_ft_printf *state);
int8_t			ft_printf_cap_x(t_arr *ret, const char **fmt,
								va_list *ap, t_ft_printf *state);
int8_t			ft_printf_cap_d(t_arr *ret, const char **fmt,
								va_list *ap, t_ft_printf *state);
int8_t			ft_printf_cap_o(t_arr *ret, const char **fmt,
								va_list *ap, t_ft_printf *state);
int8_t			ft_printf_cap_u(t_arr *ret, const char **fmt,
								va_list *ap, t_ft_printf *state);
int8_t			ft_printf_cap_c(t_arr *ret, const char **fmt,
								va_list *ap, t_ft_printf *state);
int8_t			ft_printf_c(t_arr *ret, const char **fmt,
							va_list *ap, t_ft_printf *state);
int8_t			ft_printf_cap_s(t_arr *ret, const char **fmt,
								va_list *ap, t_ft_printf *state);
int8_t			ft_printf_s(t_arr *ret, const char **fmt,
							va_list *ap, t_ft_printf *state);
int8_t			ft_printf_p(t_arr *ret, const char **fmt,
							va_list *ap, t_ft_printf *state);
int8_t			ft_printf_mod(t_arr *ret, const char **fmt,
								va_list *ap, t_ft_printf *state);
int8_t			width_handler(t_ft_printf *state, t_arr *new);
uintmax_t		get_input(va_list *ap, t_ft_printf *state);

#endif
