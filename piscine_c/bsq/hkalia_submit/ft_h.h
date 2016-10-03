/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfriedri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 14:42:00 by mfriedri          #+#    #+#             */
/*   Updated: 2016/08/03 18:00:42 by mfriedri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

char	g_empty_sq;
char	g_blocked_sq;
char	g_fill_sq;
int		g_height;
int		g_width;
int		g_xpos;
int		g_ypos;
int		g_size;
int		g_loc_x;
int		g_loc_y;

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	print_grid(char **grid);
void	draw_square(char **grid);
int		check_special_char(char c, int y, int i);
int		put_map_error(void);
void	verif(char *file);
int		test_input(int argc, char **argv);
int		ft_stdin(void);
int		close_file(char *buf, int fd);
int		get_grid(int x, int y, char *file);
int		create_str(char *file);
int		get_char_index(int y);
int		check_square(char **grid, int x, int y);
void	set_loc(int i, int j);
void	check_grid(char **grid);

#endif
