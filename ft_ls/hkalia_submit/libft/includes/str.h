/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:27:39 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/28 13:29:57 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

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

void	ft_putendl_fd(const char *src, int fd);
void	ft_putendl(const char *src);
void	ft_putstr_fd(const char *src, int fd);
void	ft_putstr(const char *src);
void	ft_strclr(char *src);
void	ft_strdel_2(int count, ...);
void	ft_strdel(char **src);
int		ft_strequ(const char *src1, const char *src2);
char	*ft_strextend(char *src, size_t len);
void	ft_striter(char *src, void (*f)(char *));
void	ft_striteri(char *src, void (*f)(unsigned int, char *));
char	*ft_strjoin_2(char *src1, char *src2);
char	*ft_strjoin(const char *src1, const char *src2);
size_t	ft_strlen_2(const char *src);
char	*ft_strmap(const char *src, char (*f)(char));
char	*ft_strmapi(const char *src, char (*f)(unsigned int, char));
int		ft_strnequ(const char *src1, const char *src2, size_t len);
char	*ft_strnew(size_t len);
char	**ft_strsplit(const char *src, char src_x);
char	*ft_strsub(const char *src, unsigned int src_i, size_t len);
char	*ft_strtrim(const char *src);

#endif
