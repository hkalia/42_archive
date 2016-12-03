/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:24:03 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/01 16:48:43 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

static bool	steep_check(t_xyxy *src)
{
	bool steep;

	steep = abs(src->y1 - src->y0) > abs(src->x1 - src->x0);
	if (steep)
	{
		swap(&src->x0, &src->y0);
		swap(&src->x1, &src->y1);
	}
	if (src->x0 > src->x1)
	{
		swap(&src->x0, &src->x1);
		swap(&src->y0, &src->y1);
	}
	return (steep);
}

void		draw_line(t_mlx *mlx, int color, t_xyxy src)
{
	bool	steep;
	t_xy	d;
	int		err;
	int		ystep;
	t_xy	c;

	steep = steep_check(&src);
	d.x = (src.x1 - src.x0);
	d.y = abs(src.y1 - src.y0);
	err = (d.x / 2);
	ystep = (src.y0 < src.y1 ? 1 : -1);
	c.y = src.y0;
	c.x = src.x0;
	while (c.x <= src.x1)
	{
		steep ? mlx_pixel_put(mlx->mlx, mlx->win, c.y, c.x, color)
				: mlx_pixel_put(mlx->mlx, mlx->win, c.x, c.y, color);
		if ((err = err - d.y) < 0)
		{
			c.y += ystep;
			err += d.x;
		}
		++c.x;
	}
}
