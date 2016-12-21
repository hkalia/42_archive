/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:49:38 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/20 14:29:48 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <strings.h>

int		mouse_press(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (x >= mlx->win.max.x || y >= mlx->win.max.y || x < 0 || y < 0)
		return (0);
	printf("\e[34mMouse Press: Button:%d X:%d Y:%d\e[0m\n", button, x, y);
	mlx->mouse.flg = 1;
	mlx->mouse.p.btn = button;
	mlx->mouse.p.pos.x = x;
	mlx->mouse.p.pos.y = y;
	return (0);
}

int		mouse_release(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (x >= mlx->win.max.x || y >= mlx->win.max.y || x < 0 || y < 0)
		return (0);
	printf("\e[34mMouse Release: Button:%d X:%d Y:%d\e[0m\n", button, x, y);
	mlx->mouse.flg = 0;
	mlx->mouse.r.btn = button;
	mlx->mouse.r.pos.x = x;
	mlx->mouse.r.pos.y = y;
	return (0);
}

int		mouse_motion(int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (x >= mlx->win.max.x || y >= mlx->win.max.y || x < 0 || y < 0)
		return (0);
	printf("\e[34mMouse Motion: X:%d Y:%d\e[0m\n", x, y);
	mlx->mouse.pos.x = x;
	mlx->mouse.pos.y = y;
	if (mlx->mouse.flg)
	{
		memset(mlx->img.img, 0, (mlx->win.max.x - 1) * mlx->img.bpp
				+ (mlx->win.max.y - 1) * mlx->img.ln);
		square(mlx, 0x00FF0000, (t_ixyxy){mlx->mouse.p.pos.x
								, mlx->mouse.p.pos.y, x, y});
		mlx_put_image_to_window(mlx->id, mlx->win.id, mlx->img.id, 0, 0);
	}
	return (0);
}
