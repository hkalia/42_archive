/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:21:34 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/13 14:02:07 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# ifndef GRDS
#  define GRD(a, b) do{if(a){return(b);}}while(0)
#  define GRD1(a, b, c) do{if(a){b;return(c);}}while(0)
#  define GRD2(a, b, c, d) do{if(a){b;c;return(d);}}while(0)
#  define GRD3(a, b, c, d, e) do{if(a){b;c;d;return(e);}}while(0)
# endif

# include <stddef.h>
# include <stdint.h>

void	*ft_memalloc(size_t len);
void	ft_memdel(void **src);
void	*ft_realloc(void *src, size_t src_sze, size_t sze);
void	*ft_reallocf(void *src, size_t src_sze, size_t sze);

#endif
