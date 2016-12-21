/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:08:34 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/21 11:31:23 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <libft.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>

# ifndef GRDS
#  define GRD(a, b) do{if(a){return(b);}}while(0)
#  define GRD1(a, b, c) do{if(a){b;return(c);}}while(0)
#  define GRD2(a, b, c, d) do{if(a){b;c;return(d);}}while(0)
#  define GRD3(a, b, c, d, e) do{if(a){b;c;d;return(e);}}while(0)
# endif

typedef struct	s_ixy
{
	int			x;
	int			y;
}				t_ixy;

typedef struct	s_ixyz
{
	int			x;
	int			y;
	int			z;
}				t_ixyz;

typedef struct	s_ixyxy
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}				t_ixyxy;

typedef struct	s_click
{
	int			btn;
	t_ixy		pos;
}				t_click;

typedef struct	s_mouse
{
	bool		flg;
	t_click		p;
	t_click		r;
	t_ixy		pos;
}				t_mouse;

typedef struct	s_img
{
	void		*id;
	char		*img;
	int			bpp;
	int			ln;
	int			end;
}				t_img;

typedef struct	s_win
{
	void		*id;
	t_ixy		max;
}				t_win;

typedef struct	s_mlx
{
	void		*id;
	t_arr		src;
	t_win		win;
	t_img		img;
	t_mouse		mouse;
}				t_mlx;

void			pixel(t_mlx *mlx, int color, t_ixy src);
void			line(t_mlx *mlx, int color, t_ixyxy src);
void			square(t_mlx *mlx, int color, t_ixyxy src);
int				key_press(int keycode, void *param);
int				key_release(int keycode, void *param);
int				mouse_press(int button, int x, int y, void *param);
int				mouse_release(int button, int x, int y, void *param);
int				mouse_motion(int x, int y, void *param);

#endif
