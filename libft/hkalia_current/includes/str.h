/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:27:39 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/10 15:28:32 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <stddef.h>

char	*ft_strnew(size_t len);
void	ft_strdel(char **src);
void	ft_strclr(char *src);
void	ft_striter(char *src, void (*f)(char *));
void	ft_striteri(char *src, void (*f)(unsigned int, char *));
char	*ft_strmap(const char *src, char (*f)(char));
char	*ft_strmapi(const char *src, char (*f)(unsigned int, char));
int		ft_strequ(const char *src1, const char *src2);
int		ft_strnequ(const char *src1, const char *src2, size_t len);
char	*ft_strsub(const char *src, unsigned int src_i, size_t len);
char	*ft_strjoin(const char *src1, const char *src2);
char	*ft_strtrim(const char *src);
char	**ft_strsplit(const char *src, char src_x);
char	*ft_strextend(char *src, size_t len);
size_t	ft_strlen_2(const char *src);
char	*ft_strjoin_2(char *src1, char *src2);
void	ft_strdel_2(int count, ...);
char	*ft_strpush(char *dst, char *src);

#endif
