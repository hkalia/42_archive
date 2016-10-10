/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 20:41:14 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/09 20:41:21 by hkalia           ###   ########.fr       */
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
int		ft_strequ(const char *src1, const char *src2);
void	ft_strdel(char **src);
char	**ft_tblnew(int len, int str_len);
void	ft_puttbl(char **tbl);
void	ft_tbldel(char **tbl);
int		main_caller(char *file);
char	*validation_caller(char	*src);
void	validate1(char *src, int *src_len, int *line_cnt);
int		validate2(char *src, int *blck_cnt);
void	assign_tbl(char **src_tbl, char *src);
int		tbl_trim(char **src_tbl);
char	*dot_nl_trim(char *src);
char	**buildboard(int size);
char	*buildrow(int size);
void	removetet(char **board, char *tet);
void	writetet(char **board, char *tet, int row, int col);
int		placetet(char **board, char *tet, int row, int col);
char	*tbl_cmp(char **src_tbl);

#endif
