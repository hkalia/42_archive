/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:55:43 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/20 16:52:17 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARR_H
# define FT_ARR_H

# include <stdint.h>
# include <stddef.h>

# define FT_ARR_GRD(a, b, c) if (a) {ft_arrreset(b); return(c);}
# define FT_ARR_INIT(a, b, c, d) a->arr_sze = b; a->arr_len = c; a->arr = d

typedef struct	s_arr
{
	size_t		arr_sze;
	size_t		arr_len;
	uint8_t		*arr;
}				t_arr;

int8_t			ft_arrinit(t_arr *src, size_t arr_sze);
void			ft_arrreset(t_arr *src);
int8_t			ft_arrdup(t_arr *dst, const t_arr *src);
int8_t			ft_arrinsertat(t_arr *dst, size_t i, const void *src
								, size_t src_len);
int8_t			ft_arrinsertat_f(t_arr *dst, size_t i, void *src
								, size_t src_len);
int8_t			ft_arrinsertarrat(t_arr *dst, size_t i, t_arr *src);
int8_t			ft_arrinsertarrat_f(t_arr *dst, size_t i, t_arr *src);

#endif
