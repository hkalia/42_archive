/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:03:28 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/10 14:24:52 by hkalia           ###   ########.fr       */
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

typedef struct	s_arr_inf
{
	size_t		elm;
	int8_t		(*init)(void *elt);
	void		(*dtr)(void *elt);
	int8_t		(*cpy)(void *dst, const void *src);
}				t_arr_inf;

typedef struct	s_arr
{
	size_t		len;
	size_t		cap;
	t_arr_inf	inf;
	uint8_t		*arr;
}				t_arr;

int8_t	arr_init(t_arr *src, t_arr_inf *src_inf, size_t cap);
void	arr_dtr(t_arr *src);
int8_t	arr_append(t_arr *src);

#endif
