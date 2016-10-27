/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 13:35:42 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/27 13:35:45 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

int		ft_isalpha(int src);
int		ft_isdigit(int src);
int		ft_isalnum(int src);
int		ft_isascii(int src);
int		ft_isprint(int src);
int		ft_toupper(int src);
int		ft_tolower(int src);
int		ft_isupper(int src);
int		ft_islower(int src);
int		ft_isblank(int src);

#endif
