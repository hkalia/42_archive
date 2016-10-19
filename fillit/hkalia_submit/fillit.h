/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 20:41:14 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/19 11:23:21 by dmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define VALIDATE3(k, j) {ret[k] = j; k++; j = 0; break;} j++

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

/*
** VALIDATORS
*/

int		*validation_caller(char	*src);
void	validate1(char *src, int *src_len, int *line_cnt);
int		check(int *a, int *b);
int		validate2(char *src, int *blck_cnt);
int		*validate3(char **src_tbl);
char	**create_compare(void);
int		*nbrstrnew(int size, int stop);

/*
** STR FUNCTIONS
*/

void	ft_putchar(char src);
void	ft_putnbr(int src);
void	ft_putnbrstr(int *src);
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

int		solve_caller(int *tetindex);
char	**buildboard(int size, int str_size);
char	**finishboard(char **board, int size, int str_size, int i);
void	removetet(char **board, char *tet);
void	writetet(char **board, char *tet, int row, int col);
int		checktet(char **board, char *tet, int row, int col);
int		recursor(char **board, char **tetarray, int row, int col);
void	cleanup_board(char **board);
int		find_board_size(int *tetindex);
char	**createtet(int *tetindex);
char	*createtet2(int tet);
char	*createtet3(int tet, char *str);
char	**convertarray(char **tetarray);

/*
** OTHER
*/

void	ft_putnbrstr(int *src);
int		main_caller(char *file);

#endif
