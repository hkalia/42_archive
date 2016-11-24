/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:55:43 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/21 17:42:23 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARR_H
# define FT_ARR_H

# include <stdint.h>
# include <stddef.h>

# ifndef FT_GRD
#  define FT_GRD(a, b) if (a) {return(b);}
# endif

# ifndef FT_GRD1
#  define FT_GRD1(a, b, c) if (a) {b; return(c);}
# endif

# ifndef FT_GRD2
#  define FT_GRD2(a, b, c, d) if (a) {b; c; return(d);}
# endif

# define FT_ARR_INIT(a, b, c, d) a.arr_sze = b; a.arr_len = c; a.arr = d;
# define FT_ARR_INIT2(a, b, c, d) a->arr_sze = b; a->arr_len = c; a->arr = d;

typedef struct	s_arr
{
	size_t		arr_sze;
	size_t		arr_len;
	uint8_t		*arr;
}				t_arr;

int8_t			ft_arrinit(t_arr *src, size_t arr_sze);
int8_t			ft_arrdup(t_arr *dst, const t_arr *src);
int8_t			ft_arrinsertat(t_arr *dst, size_t i, const void *src
								, size_t src_len);
int8_t			ft_arrinsertarrat(t_arr *dst, size_t i, t_arr *src);
void			ft_arrreset(t_arr *src);
void			ft_arrreset_f(t_arr *src);
int8_t			ft_arrremoveat(t_arr *src, size_t i, size_t size);
char			*ft_arrtostr(t_arr *src);

#endif
