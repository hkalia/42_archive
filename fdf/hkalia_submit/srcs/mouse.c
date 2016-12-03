/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:49:38 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/01 17:44:15 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		mouse_press(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	printf("\e[34mMouse Press: Button:%d X:%d Y:%d\e[0m\n", button, x, y);
	mlx->mouse.flg = 1;
	mlx->mouse.press.btn = button;
	mlx->mouse.press.pos.x = x;
	mlx->mouse.press.pos.y = y;
	return (0);
}

int		mouse_release(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	printf("\e[34mMouse Release: Button:%d X:%d Y:%d\e[0m\n", button, x, y);
	mlx->mouse.flg = 0;
	mlx->mouse.release.btn = button;
	mlx->mouse.release.pos.x = x;
	mlx->mouse.release.pos.y = y;
	return (0);
}

int		mouse_motion(int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	printf("\e[34mMouse Motion: X:%d Y:%d\e[0m\n", x, y);
	mlx->mouse.pos.x = x;
	mlx->mouse.pos.y = y;
	return (0);
}
