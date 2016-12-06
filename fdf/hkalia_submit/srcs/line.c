/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:24:03 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/03 17:49:09 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		line(t_mlx *mlx, int color, t_xyxy src)
{
	t_xy	d;
	t_xy	s;
	int		e1;
	int		e2;

	d.x = abs(src.x1 - src.x0);
	d.y = abs(src.y1 - src.y0);
	s.x = src.x0 < src.x1 ? 1 : -1;
	s.y = src.y0 < src.y1 ? 1 : -1;
	e1 = (d.x > d.y ? d.x : -d.y) / 2;
	while (!(src.x0 == src.x1 && src.y0 == src.y1))
	{
		pixel(mlx, color, (t_xy){src.x0, src.y0});
		e2 = e1;
		if (e2 > -d.x)
		{
			e1 -= d.y;
			src.x0 += s.x;
		}
		if (e2 < d.y)
		{
			e1 += d.x;
			src.y0 += s.y;
		}
	}
}
