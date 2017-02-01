/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 12:09:59 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/01 11:02:33 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRIVATE_H
# define FT_PRINTF_PRIVATE_H

# include <ft_printf.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>

typedef struct		s_ft_printf_arr
{
	char			*ptr;
	size_t			len;
	size_t			cap;
}					t_ft_printf_arr;

/*
**					0x1 flg_minus;
**					0x2 flg_plus;
**					0x4 flg_space;
**					0x8 flg_hash;
**					0x10 flg_zero;
**					0x20 flg_dot;
*/

typedef struct		s_ft_printf
{
	t_ft_printf_arr	new;
	uint8_t			flgs;
	int				width;
	int				dot;
	uint8_t			len_mod;
}					t_ft_printf;

int					ft_vasprintf(char **ret, const char *fmt, va_list arg);
int8_t				ft_printf_line(t_ft_printf_arr *ret, const char **fmt
									, t_ft_printf *s);
int8_t				ft_printf_flags(t_ft_printf_arr *ret, const char **fmt
									, va_list arg, t_ft_printf *s);
int8_t				ft_printf_width(t_ft_printf_arr *ret, const char **fmt
									, va_list arg, t_ft_printf *s);
int8_t				ft_printf_width_h(t_ft_printf *s);
int8_t				ft_printf_dot(t_ft_printf_arr *ret, const char **fmt
									, va_list arg, t_ft_printf *s);
int8_t				ft_printf_dot_h_ux(t_ft_printf *s);
int8_t				ft_printf_hh(t_ft_printf_arr *ret, const char **fmt
									, va_list arg, t_ft_printf *s);
int8_t				ft_printf_h(t_ft_printf_arr *ret, const char **fmt
								, va_list arg, t_ft_printf *s);
int8_t				ft_printf_l(t_ft_printf_arr *ret, const char **fmt
								, va_list arg, t_ft_printf *s);
int8_t				ft_printf_ll(t_ft_printf_arr *ret, const char **fmt
									, va_list arg, t_ft_printf *s);
int8_t				ft_printf_j(t_ft_printf_arr *ret, const char **fmt
								, va_list arg, t_ft_printf *s);
int8_t				ft_printf_z(t_ft_printf_arr *ret, const char **fmt
								, va_list arg, t_ft_printf *s);
uintmax_t			ft_printf_len_mod_oux(va_list arg, t_ft_printf *s);
int8_t				ft_printf_d(t_ft_printf_arr *ret, const char **fmt
								, va_list arg, t_ft_printf *s);
int8_t				ft_printf_o(t_ft_printf_arr *ret, const char **fmt
								, va_list arg, t_ft_printf *s);
int8_t				ft_printf_u(t_ft_printf_arr *ret, const char **fmt
								, va_list arg, t_ft_printf *s);
int8_t				ft_printf_x(t_ft_printf_arr *ret, const char **fmt
								, va_list arg, t_ft_printf *s);
int8_t				ft_printf_cap_x(t_ft_printf_arr *ret, const char **fmt
									, va_list arg, t_ft_printf *s);
int8_t				ft_printf_cap_d(t_ft_printf_arr *ret, const char **fmt
									, va_list arg, t_ft_printf *s);
int8_t				ft_printf_cap_o(t_ft_printf_arr *ret, const char **fmt
									, va_list arg, t_ft_printf *s);
int8_t				ft_printf_cap_u(t_ft_printf_arr *ret, const char **fmt
									, va_list arg, t_ft_printf *s);
int					ft_printf_wctomb(char *s, wchar_t wchar);
int8_t				ft_printf_cap_c(t_ft_printf_arr *ret, const char **fmt
									, va_list arg, t_ft_printf *s);
int8_t				ft_printf_c(t_ft_printf_arr *ret, const char **fmt
								, va_list arg, t_ft_printf *s);
int8_t				ft_printf_cap_s(t_ft_printf_arr *ret, const char **fmt
									, va_list arg, t_ft_printf *s);
int8_t				ft_printf_s(t_ft_printf_arr *ret, const char **fmt
								, va_list arg, t_ft_printf *s);
int8_t				ft_printf_p(t_ft_printf_arr *ret, const char **fmt
								, va_list arg, t_ft_printf *s);
int8_t				ft_printf_mod(t_ft_printf_arr *ret, const char **fmt
									, va_list arg, t_ft_printf *s);
int8_t				ft_printf_arr_init(t_ft_printf_arr *src, size_t cap);
int8_t				ft_printf_arr_reserve(t_ft_printf_arr *src, size_t sze);
int8_t				ft_printf_arr_resize(t_ft_printf_arr *src, size_t sze);
char				*ft_printf_arr_tostr(t_ft_printf_arr *src);
void				ft_printf_arr_dtr(t_ft_printf_arr *src);
int8_t				ft_printf_arr_insert(t_ft_printf_arr *dst, size_t idx
										, const void *src);
int8_t				ft_printf_arr_insertm(t_ft_printf_arr *dst, size_t idx
											, const void *src, size_t src_len);
int8_t				ft_printf_arr_insertarr(t_ft_printf_arr *dst, size_t idx
											, t_ft_printf_arr *src);
int8_t				ft_printf_arr_removem(t_ft_printf_arr *src, size_t idx
											, size_t len);
int8_t				ft_printf_arr_append(t_ft_printf_arr *dst, const void *src);
int8_t				ft_printf_arr_appendm(t_ft_printf_arr *dst, const void *src
											, size_t src_len);
int8_t				ft_printf_arr_appendarr(t_ft_printf_arr *dst
											, t_ft_printf_arr *src);
void				ft_printf_bzero(void *src, size_t len);
void				*ft_printf_memset(void *dst, int src, size_t len);
void				*ft_printf_memcpy(void *dst, const void *src, size_t len);
void				*ft_printf_memmove(void *dst, const void *src, size_t len);
size_t				ft_printf_strlen(const char *src);
char				*ft_printf_strdup(const char *src);
char				*ft_printf_strchr(const char *src, int src_x);
char				*ft_printf_itoa(intmax_t src);
char				*ft_printf_itoa_base(uintmax_t src, short base
										, const char *spec);

#endif
