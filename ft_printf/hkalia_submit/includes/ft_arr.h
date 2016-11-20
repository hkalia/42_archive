/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:55:43 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/19 18:46:11 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARR_H
# define FT_ARR_H

# include <stdint.h>
# include <stddef.h>

# define FT_ARR_GRD(a, b, c) if (a) {ft_arrdel(b); return(c);}

typedef struct	s_arr
{
	size_t		arr_sze;
	size_t		arr_len;
	uint8_t		*arr;
}				t_arr;

t_arr			*ft_arrnew(size_t arr_sze);
int8_t			ft_arrinsertat(t_arr **dst, size_t i, const void *src
								, size_t src_len);
int8_t			ft_arrinsertat_f(t_arr **dst, size_t i, void *src
									, size_t src_len);
int8_t			ft_arrinsertarrat_f(t_arr **dst, size_t i, t_arr **src);
void			ft_arrdel(t_arr **src);

#endif
