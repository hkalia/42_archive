/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:53:00 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/28 13:29:33 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# ifndef GRDS
#  define GRD1(a, b) do{if(a){b;}}while(0)
#  define GRD2(a, b, c) do{if(a){b;c;}}while(0)
#  define GRD3(a, b, c, d) do{if(a){b;c;d;}}while(0)
#  define GRD4(a, b, c, d, e) do{if(a){b;c;d;e;}}while(0)
#  define GRD5(a, b, c, d, e, f) do{if(a){b;c;d;e;f;}}while(0)
#  define GRD6(a, b, c, d, e, f, g) do{if(a){b;c;d;e;f;g;}}while(0)
#  define GRD7(a, b, c, d, e, f, g, h) do{if(a){b;c;d;e;f;g;h;}}while(0)
#  define GRD8(a, b, c, d, e, f, g, h, i) do{if(a){b;c;d;e;f;g;h;i;}}while(0)
# endif

# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdarg.h>
# include "arr.h"



/*
**	if you add to the below struct, please be sure to update the dispatcher
*/

typedef struct	s_ft_printf
{
	t_arr		ret;
	const char	*fmt;
	va_list		*ap;
	t_arr		new;
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
int				ft_dprintf(int fd, const char *fmt, ...);
int				ft_asprintf(char **ret, const char *fmt, ...);
int				ft_vprintf(const char *fmt, va_list *ap);
int				ft_vdprintf(int fd, const char *fmt, va_list *ap);
int				ft_vasprintf(char **ret, const char *fmt, va_list *ap);
int				ft_putchar(int src);

/*
**	PART OF PRINTF
*/

int8_t			ft_printf_flags(t_ft_printf *s);
int8_t			ft_printf_width(t_ft_printf *s);
int8_t			ft_printf_dot(t_ft_printf *s);
int8_t			ft_printf_hh(t_ft_printf *s);
int8_t			ft_printf_h(t_ft_printf *s);
int8_t			ft_printf_l(t_ft_printf *s);
int8_t			ft_printf_ll(t_ft_printf *s);
int8_t			ft_printf_j(t_ft_printf *s);
int8_t			ft_printf_z(t_ft_printf *s);
int8_t			ft_printf_d(t_ft_printf *s);
int8_t			ft_printf_o(t_ft_printf *s);
int8_t			ft_printf_u(t_ft_printf *s);
int8_t			ft_printf_x(t_ft_printf *s);
int8_t			ft_printf_cap_x(t_ft_printf *s);
int8_t			ft_printf_cap_d(t_ft_printf *s);
int8_t			ft_printf_cap_o(t_ft_printf *s);
int8_t			ft_printf_cap_u(t_ft_printf *s);
int8_t			ft_printf_cap_c(t_ft_printf *s);
int8_t			ft_printf_c(t_ft_printf *s);
int8_t			ft_printf_cap_s(t_ft_printf *s);
int8_t			ft_printf_s(t_ft_printf *s);
int8_t			ft_printf_p(t_ft_printf *s);
int8_t			ft_printf_mod(t_ft_printf *s);
int8_t			width_handler(t_ft_printf *s);
int8_t			dot_handler_ux(t_ft_printf *s);
uintmax_t		get_input(t_ft_printf *s);

#endif
