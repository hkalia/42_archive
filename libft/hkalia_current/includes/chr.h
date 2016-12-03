/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:09:09 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/02 17:51:34 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHR_H
# define CHR_H

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
int	ft_putchar_fd(int src, int fd);
int	ft_putchar(int src);
int	ft_tolower(int src);
int	ft_toupper(int src);

#endif
