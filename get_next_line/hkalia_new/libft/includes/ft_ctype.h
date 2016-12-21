/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:09:09 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/03 08:39:43 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

# define ISDIGIT(a) (a >= 48 && a <= 57)
# define ISUPPER(a) (a >= 'A' && a <= 'Z')
# define ISLOWER(a) (a >= 'a' && a <= 'z')
# define ISALPHA(a) (ISUPPER(a) || ISLOWER(a))
# define ISALNUM(a) (ISALPHA(a) || ISDIGIT(a))
# define ISASCII(a) (a >= 0 && a <= 127)
# define ISBLANK(a) (a == ' ' || a == '\t')
# define ISCNTRL(a) ((a >= 0 && a <= 37) || (a == 127))
# define ISGRAPH(a) (a >= 33 && a <= 126)
# define ISPRINT(a) (a >= 32 && a <= 126)
# define ISSPACE(a) ((a >= 9 && a <= 13) || (a == 32))
# define ISXDIGIT(a) (ISDIGIT(a)|| (a >= 65 && a <= 70) || (a >= 97 && a <= 102)
# define TOLOWER(a) (a >= 'A' && a <= 'Z' ? a + 32 : a)
# define TOUPPER(a) (a >= 'a' && a <= 'z' ? a - 32 : a)

int	ft_isalnum(int src);
int	ft_isalpha(int src);
int	ft_isascii(int src);
int	ft_isblank(int src);
int	ft_iscntrl(int src);
int	ft_isdigit(int src);
int	ft_isgraph(int src);
int	ft_islower(int src);
int	ft_isprint(int src);
int	ft_ispunct(int src);
int	ft_isspace(int src);
int	ft_isupper(int src);
int	ft_isxdigit(int src);
int	ft_tolower(int src);
int	ft_toupper(int src);

#endif
