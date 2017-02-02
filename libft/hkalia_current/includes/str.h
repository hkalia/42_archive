/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:27:39 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 12:19:17 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# ifndef GRDS
#  define GRD(a, b) do{if(a){return(b);}}while(0)
#  define GRD1(a, b, c) do{if(a){b;return(c);}}while(0)
#  define GRD2(a, b, c, d) do{if(a){b;c;return(d);}}while(0)
#  define GRD3(a, b, c, d, e) do{if(a){b;c;d;return(e);}}while(0)
#  define GRD4(a, b, c, d, e, f) do{if(a){b;c;d;e;return(f);}}while(0)
#  define GRD5(a, b, c, d, e, f, g) do{if(a){b;c;d;e;f;return(g);}}while(0)
#  define GRD6(a, b, c, d, e, f, g, h) do{if(a){b;c;d;e;f;g;return(h);}}while(0)
# endif

# include <stddef.h>

void	ft_putendl_fd(int fd, const char *src);
void	ft_putendl(const char *src);
void	ft_putstr_fd(int fd, const char *src);
void	ft_putstr(const char *src);
void	ft_strclr(char *src);
void	ft_strdel(char **src);
int		ft_strequ(const char *src1, const char *src2);
void	ft_striter(char *src, void (*f)(char *));
void	ft_striteri(char *src, void (*f)(unsigned int, char *));
char	*ft_strjoin(const char *src1, const char *src2);
char	*ft_strmap(const char *src, char (*f)(char));
char	*ft_strmapi(const char *src, char (*f)(unsigned int, char));
int		ft_strnequ(const char *src1, const char *src2, size_t len);
char	*ft_strnew(size_t len);
char	**ft_strsplit(const char *src, char src_x);
char	*ft_strsub(const char *src, unsigned int src_i, size_t len);
char	*ft_strtrim(const char *src);

#endif
