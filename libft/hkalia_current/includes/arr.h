/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:03:28 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/03 07:59:43 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARR_H
# define ARR_H

# include <stdint.h>
# include <stddef.h>

# ifndef GRD
#  define GRD(a, b) if (a) {return(b);}
# endif

# ifndef GRD1
#  define GRD1(a, b, c) if (a) {b; return(c);}
# endif

# ifndef GRD2
#  define GRD2(a, b, c, d) if (a) {b; c; return(d);}
# endif

# define ARR_INIT_CAP 4
# define ARR_INIT(a, b, c, d) a.sze = b; a.len = c; a.arr = d;
# define ARR_INIT1(a, b, c, d) a->sze = b; a->len = c; a->arr = d;

typedef struct	s_arr
{
	size_t		elem;
	size_t		len;
	size_t		cap;
	void		*arr;
}				t_arr;

#endif
