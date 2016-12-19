/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:27:06 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/18 09:53:55 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <string.h>

t_img	img_new(t_mlx *mlx)
{
	t_img	ret;

	bzero(&ret, sizeof(t_img));
	GRD((ret.id = mlx_new_image(mlx->id, mlx->win.max.x, mlx->win.max.y)) == 0
		, ret);
	ret.img = mlx_get_data_addr(ret.id, &ret.bpp, &ret.ln, &ret.end);
	ret.bpp /= 8;
	return (ret);
}
