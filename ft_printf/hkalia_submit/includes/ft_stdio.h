/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 13:09:29 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/02 16:42:20 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <stdbool.h>
# include <stdarg.h>

# define PRINTF_CONV_1 "S", "s", "U", "u", "X", "x"
# define PRINTF_CONV "C", "c", "D", "d", "i", "O", "o", "p", PRINTF_CONV_1
# define PRINTF_LEN "hh", "h", "l", "ll", "j", "z",
# define PRINTF_MINWID "*", "1", "2", "3", "4", "5", "6", "7", "8", "9"
# define PRINTF_FLAGS "%", "-", "+", " ", "#", "0"
# define PRINTF_SPEC {PRINTF_FLAGS, PRINTF_MINWID, ".", PRINTF_LEN, PRINTF_CONV}
/*
**	The above are checked in order after the %, if there is a match they are
**	passed to the corresponding function below.
*/
# define PRINTF_FFLAGS ft_printf_flag_percent
# define PRINTF_FARR {PRINTF_FFLAGS}
# define STR_GUARD(a, b, c) if (a) {ft_strdel(b); return (c);}

typedef struct	s_printf_store
{
	bool		flag_minus;
	bool		flag_plus;
	bool		flag_space;
	bool		flag_hash;
	bool		flag_zero;
	int			flag_min_field_width;
	int			flag_precision;
	int			flag_len_mod;
}				t_printf_store;
typedef int	(*t_printf_func_ptr)(char **, va_list *, t_printf_store *);

int				ft_putchar(int src);
int				ft_asprintf(char **ret, const char *fmt, ...);

#endif
