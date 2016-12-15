/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:53:00 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/15 15:04:54 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdarg.h>
# include "arr.h"

# ifndef GRDS
#  define GRD(a, b) do{if(a){return(b);}}while(0)
#  define GRD1(a, b, c) do{if(a){b;return(c);}}while(0)
#  define GRD2(a, b, c, d) do{if(a){b;c;return(d);}}while(0)
#  define GRD3(a, b, c, d, e) do{if(a){b;c;d;return(e);}}while(0)
# endif

typedef struct	s_ft_printf
{
	bool		flg_minus;
	bool		flg_plus;
	bool		flg_space;
	bool		flg_hash;
	bool		flg_zero;
	int			int_width;
	bool		flg_dot;
	int			int_dot;
	int			int_len_mod;
}				t_ft_printf;

int				ft_printf(const char *fmt, ...);
int				ft_putchar(int src);
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
int8_t			width_handler_cs(t_ft_printf *state, t_arr *new);
uintmax_t		get_input(va_list *ap, t_ft_printf *state);

#endif
