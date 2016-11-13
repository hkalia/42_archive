/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 13:14:12 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/13 11:30:49 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUSTOM_H
# define FT_CUSTOM_H

# include <string.h>
# include <wchar.h>

# define TBLGUARD(a, b, c) if(a) {ft_tbldel(b); return (c);}
# define BUFF_SIZE 1

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
**	MEM
*/

void				*ft_memalloc(size_t len);
void				ft_memdel(void **src);

/*
**	STR
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
char				*ft_strextend(char *src, size_t len);
size_t				ft_strlen_2(const char *src);

/*
**	TBL
*/

char				**ft_tblnew(int len);
char				**ft_tblnew_2(int len, int str_len);
void				ft_tbldel(char **tbl);

/*
**	NBR
*/

size_t				ft_nbrlen(ssize_t src);

/*
**	PUT
*/

void				ft_putstr(const char *src);
void				ft_putendl(const char *src);
void				ft_putnbr(int src);
void				ft_putchar_fd(char src, int fd);
void				ft_putstr_fd(const char *src, int fd);
void				ft_putendl_fd(const char *src, int fd);
void				ft_putnbr_fd(int src, int fd);
void				ft_putnbr_base(long long src, int base);
void				ft_puttbl(char **tbl);
void				ft_putlststr(t_list *elem);
void				ft_putnbrstr(int *src, int stop);

/*
**	LST
*/

t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstaddend(t_list *lst, t_list *new);

/*
**	OTHER
*/

char				*ft_itoa(int src);
int					get_next_line(const int fd, char **line);
int					ft_wcstombs(char **dst, const wint_t *src);

#endif
