/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:30:35 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/05 12:20:48 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static uint32_t	endian_change(uint32_t value)
{
	uint32_t	result = 0;

	result |= (value & 0x000000FF) << 24;
	result |= (value & 0x0000FF00) << 8;
	result |= (value & 0x00FF0000) >> 8;
	result |= (value & 0xFF000000) >> 24;
	return (result);
}

void			pixel(t_mlx *mlx, int color, t_xy src)
{
	int	*i;

	if (src.x >= mlx->win.max.x || src.y >= mlx->win.max.y || src.x < 0
		|| src.y < 0)
		return ;
	i = (int *)&mlx->img.img[src.x * mlx->img.bpp + src.y * mlx->img.ln];
	*i = mlx->img.end ? endian_change(color) : color;
}
