/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:53:00 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/05 14:49:56 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <stdbool.h>
# include <stdarg.h>
# include <ft_custom.h>

typedef struct	s_printf_parse
{
	bool		flag_minus;
	bool		flag_plus;
	bool		flag_space;
	bool		flag_hash;
	bool		flag_zero;
	int			int_width;
	int			int_dot;
	int			flag_len_mod;
}				t_printf_parse;
typedef int	(*t_printf_func_ptr)(char **ret, const char **fmt,\
								va_list *ap, t_printf_parse *parse_state);

# define PRINTF_STR_GRD(a, b, c) if (a) {ft_strdel(b); return (c);}
# define PRINTF_SPEC_LEN 37

int				ft_putchar(int src);
int				ft_asprintf(char **ret, const char *fmt, ...);

/*
**	PART OF PRINTF
*/

int				ft_printf_flags(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_width(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_dot(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);
int				ft_printf_mod(char **ret, const char **fmt,
								va_list *ap, t_printf_parse *parse_state);

#endif
