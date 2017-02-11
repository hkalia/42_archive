/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 13:09:41 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/03 09:29:34 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stddef.h>

/*
**	MEM
*/

void	ft_bzero(void *src, size_t len);
void	*ft_memccpy(void *dst, const void *src, int src_x
					, size_t len);
void	*ft_memchr(const void *src, int src_x, size_t len);
int		ft_memcmp(const void *src1, const void *src2, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *dst, int src, size_t len);

/*
**	STR
*/

char	*ft_strcat(char *src1, const char *src2);
char	*ft_strchr(const char *src, int src_x);
int		ft_strcmp(const char *src1, const char *src2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *src1);
size_t	ft_strlcat(char *dst, const char *src, size_t len);
size_t	ft_strlen(const char *src);
char	*ft_strncat(char *src1, const char *src2, size_t len);
int		ft_strncmp(const char *src1, const char *src2, size_t len);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strndup(const char *src, size_t len);
size_t	ft_strnlen(const char *src, size_t len);
char	*ft_strnstr(const char *big, const char *lit, size_t len);
char	*ft_strrchr(const char *src, int src_x);
char	*ft_strstr(const char *big, const char *lit);

#endif
