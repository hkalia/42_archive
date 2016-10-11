/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 20:41:14 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/10 19:46:51 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

/*
** VALIDATORS
*/

int		*validation_caller(char	*src);
void	validate1(char *src, int *src_len, int *line_cnt);
int		validate2(char *src, int *blck_cnt);
int		*validate3(char **src_tbl);
char	**create_compare(void);

/*
** STR FUNCTIONS
*/

void	ft_putstr(const char *src);
void	ft_putendl(const char *src);
char	*ft_strnew(int len);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strequ(const char *src1, const char *src2);
void	ft_strdel(char **src);

/*
** DEFAULT TABLE FUNCTIONS
*/

char	**ft_tblnew(int len, int str_len);
void	ft_puttbl(char **tbl);
void	ft_tbldel(char **tbl);

/*
** SPECIFIC TABLE FUNCTIONS
*/

void	assign_tbl(char **src_tbl, char *src);
int		tbl_trim(char **src_tbl);
char	*dot_nl_trim(char *src);

/*
** SOLVER FUNCTIONS
*/

char	**buildboard(int size, int str_size);
void	removetet(char **board, char c);
void	writetet(char **board, char *tet, int row, int col);
int		placetet(char **board, char *tet, int row, int col);

/*
** OTHER
*/

void	ft_putnbrstr(int *src);
int		main_caller(char *file);

#endif
