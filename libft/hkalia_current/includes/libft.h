/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:40:49 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/06 18:23:39 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define TBLDEL_RETURN(a, b, c) if(a) {ft_tbldel(b); return (c);}

# include <string.h>

/*
**	LIBC FUNCTIONS (MEM) (MANDATORY)
*/

void				*ft_memset(void *dst, int src, size_t len);
void				ft_bzero(void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int src_x,
								size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *src, int src_x, size_t len);
int					ft_memcmp(const void *src1, const void *src2, size_t len);

/*
**	LIBC FUNCTIONS (STR) (MANDATORY)
*/

size_t				ft_strlen(const char *src);
char				*ft_strdup(const char *src1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *src1, const char *src2);
char				*ft_strncat(char *src1, const char *src2, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t len);
char				*ft_strchr(const char *src, int src_x);
char				*ft_strrchr(const char *src, int src_x);
char				*ft_strstr(const char *big, const char *lit);
char				*ft_strnstr(const char *big, const char *lit, size_t len);
int					ft_strcmp(const char *src1, const char *src2);
int					ft_strncmp(const char *src1, const char *src2, size_t len);
int					ft_atoi(const char *src);

/*
**	LIBC FUNCTIONS (IS) (MANDATORY)
*/

int					ft_isalpha(int src);
int					ft_isdigit(int src);
int					ft_isalnum(int src);
int					ft_isascii(int src);
int					ft_isprint(int src);
int					ft_toupper(int src);
int					ft_tolower(int src);

/*
**	42 FUNCTIONS (MEM) (MANDATORY)
*/

void				*ft_memalloc(size_t len);
void				ft_memdel(void **src);

/*
**	42 FUNCTIONS (STR) (MANDATORY)
*/

char				*ft_strnew(size_t len);
void				ft_strdel(char **src);
void				ft_strclr(char *src);
void				ft_striter(char *src, void (*f)(char *));
void				ft_striteri(char *src, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *src, char (*f)(char));
char				*ft_strmapi(const char *src, char (*f)(unsigned int, char));
int					ft_strequ(const char *src1, const char *src2);
int					ft_strnequ(const char *src1, const char *src2, size_t len);
char				*ft_strsub(const char *src, unsigned int src_i, size_t len);
char				*ft_strjoin(const char *src1, const char *src2);
char				*ft_strtrim(const char *src);
char				**ft_strsplit(const char *src, char src_x);
char				*ft_itoa(int src);
void				ft_putchar(char src);
void				ft_putstr(const char *src);
void				ft_putendl(const char *src);
void				ft_putnbr(int src);
void				ft_putchar_fd(char src, int fd);
void				ft_putstr_fd(const char *src, int fd);
void				ft_putendl_fd(const char *src, int fd);
void				ft_putnbr_fd(int src, int fd);

/*
**	42 FUNCTIONS (LST) (BONUS)
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
**	LIBC FUNCTIONS (STR) (EXTRA)
*/

char				*ft_strextend(char *src, size_t len);
size_t				ft_strlen2(const char *src);
size_t				ft_strnlen(const char *src, size_t len);
char				*ft_strndup(const char *src, size_t len);
void				ft_putnbrstr(int *src, int stop);

/*
**	LIBC FUNCTIONS (IS) (EXTRA)
*/

int					ft_isupper(int src);
int					ft_islower(int src);
int					ft_isblank(int src);

/*
**	CUSTOM FUNCTIONS (LST) (EXTRA)
*/

void				ft_putlststr(t_list *elem);
void				ft_lstaddend(t_list *lst, t_list *new);

/*
**	CUSTOM FUNCTIONS (TBL) (EXTRA)
*/

char				**ft_tblnew(int len);
char				**ft_tblnew2(int len, int str_len);
void				ft_tbldel(char **tbl);
void				ft_puttbl(char **tbl);

/*
**	CUSTOM FUNCTIONS (EXTRA)
*/

ssize_t				ft_nbrlen(ssize_t src);

#endif
