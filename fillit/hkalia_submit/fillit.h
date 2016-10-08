/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_hdr.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 14:50:08 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/07 15:30:03 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

void	ft_putstr(const char *src);
void	ft_putendl(const char *src);
char	*ft_strnew(size_t len);
void	ft_strdel(char **src);
char	**ft_tblnew(size_t len);
void	ft_puttbl(char **tbl);
void	ft_tbldel(char **tbl);

#endif
