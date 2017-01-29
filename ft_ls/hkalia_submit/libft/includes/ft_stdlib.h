/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 13:09:37 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/28 13:29:42 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# ifndef GRDS
#  define GRD1(a, b) do{if(a){b;}}while(0)
#  define GRD2(a, b, c) do{if(a){b;c;}}while(0)
#  define GRD3(a, b, c, d) do{if(a){b;c;d;}}while(0)
#  define GRD4(a, b, c, d, e) do{if(a){b;c;d;e;}}while(0)
#  define GRD5(a, b, c, d, e, f) do{if(a){b;c;d;e;f;}}while(0)
#  define GRD6(a, b, c, d, e, f, g) do{if(a){b;c;d;e;f;g;}}while(0)
#  define GRD7(a, b, c, d, e, f, g, h) do{if(a){b;c;d;e;f;g;h;}}while(0)
#  define GRD8(a, b, c, d, e, f, g, h, i) do{if(a){b;c;d;e;f;g;h;i;}}while(0)
# endif


# include <stddef.h>

int		ft_abs(int src);
int		ft_atoi(const char *src);
void	*ft_calloc(size_t count, size_t size);
int		ft_wctomb(char *s, wchar_t wchar);

#endif
