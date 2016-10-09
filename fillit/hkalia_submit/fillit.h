/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_hdr.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 14:50:08 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/08 17:56:04 by hkalia           ###   ########.fr       */
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
char	*ft_strnew(int len);
char	*ft_strcpy(char *dst, const char *src);
void	ft_strdel(char **src);
char	**ft_tblnew(int len);
void	ft_puttbl(char **tbl);
void	ft_tbldel(char **tbl);
int		main_caller(char *file);
char	**validation_caller(char	*src);
void	validate1(char *src, int *src_len, int *line_cnt);
int		validate2(char *src, int *blck_cnt);
void	assign_tbl(char **src_tbl, char *src);
int		tbl_trim(char **src_tbl);
char	*dot_nl_trim(char *src);

#endif
