/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:27:06 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/05 12:58:43 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	img_new(t_mlx *mlx)
{
	if (!(mlx->img.id = mlx_new_image(mlx->id, mlx->win.max.x, mlx->win.max.y)))
	{
		mlx_destroy_window(mlx->id, mlx->win.id);
		perror("\e[31mERROR: mlx_new_image\e[0m\n");
		exit(-1);
	}
	mlx->img.img = mlx_get_data_addr(mlx->img.id, &mlx->img.bpp, &mlx->img.ln
									, &mlx->img.end);
	mlx->img.bpp /= 8;
}
