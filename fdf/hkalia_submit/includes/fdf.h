/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:08:34 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/01 17:38:24 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>

# ifndef FT_GRD
#  define FT_GRD(a, b) if (a) {return(b);}
# endif

# ifndef FT_GRD1
#  define FT_GRD1(a, b, c) if (a) {b; return(c);}
# endif

# ifndef FT_GRD2
#  define FT_GRD2(a, b, c, d) if (a) {b; c; return(d);}
# endif

typedef struct	s_xy
{
	int			x;
	int			y;
}				t_xy;

typedef struct	s_xyxy
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}				t_xyxy;

typedef struct	s_xyzc
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_xyzc;

typedef struct	s_click
{
	int			btn;
	t_xy		pos;
}				t_click;

typedef struct	s_mouse
{
	bool		flg;
	t_click		press;
	t_click		release;
	t_xy		pos;
}				t_mouse;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_xy		max;
	t_mouse		mouse;
}				t_mlx;

void			draw_line(t_mlx *mlx, int color, t_xyxy src);
int				key_press(int keycode, void *param);
int				key_release(int keycode, void *param);
int				mouse_press(int button, int x, int y, void *param);
int				mouse_release(int button, int x, int y, void *param);
int				mouse_motion(int x, int y, void *param);

#endif
