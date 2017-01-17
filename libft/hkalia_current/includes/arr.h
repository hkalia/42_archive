/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:03:28 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/15 13:18:00 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARR_H
# define ARR_H

# ifndef GRDS
#  define GRD(a, b) do{if(a){return(b);}}while(0)
#  define GRD1(a, b, c) do{if(a){b;return(c);}}while(0)
#  define GRD2(a, b, c, d) do{if(a){b;c;return(d);}}while(0)
#  define GRD3(a, b, c, d, e) do{if(a){b;c;d;return(e);}}while(0)
# endif

# include <stddef.h>
# include <stdint.h>

typedef struct	s_arr
{
	size_t		elm;
	size_t		len;
	size_t		cap;
	uint8_t		*arr;
}				t_arr;

void			arr_dtr(t_arr *src);
int8_t			arr_init(t_arr *src, size_t cap);
int8_t			arr_insertat(t_arr *dst, size_t i, const void *src
							, size_t src_len);
int8_t			arr_removeat(t_arr *src, size_t i, size_t len);
int8_t			arr_reserve(t_arr *src, size_t sze);
char			*arr_tostr(t_arr *src);

#endif
