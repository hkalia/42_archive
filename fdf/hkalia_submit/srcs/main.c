/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:16:04 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/02 16:00:18 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <strings.h>

int		loop_hook(void *param)
{
	t_mlx	*mlx;
	t_xyxy	test;

	mlx = (t_mlx *)param;
	if (mlx->mouse.flg)
	{
		test.x0 = mlx->mouse.press.pos.x;
		test.y0 = mlx->mouse.press.pos.y;
		test.x1 = mlx->mouse.pos.x;
		test.y1 = mlx->mouse.pos.y;
		mlx_clear_window(mlx->mlx, mlx->win);
		draw_line(mlx, 0x00FF0000, test);
	}
	return(0);
}

int		mlx_start(t_mlx *mlx)
{
	FT_GRD1(!(mlx->mlx = mlx_init()), perror("\e[31mERROR: mlx_init\e[0m\n")
			, -1);
	mlx->max.x = 1920;
	mlx->max.y = 1080;
	FT_GRD1(!(mlx->win = mlx_new_window(mlx->mlx, mlx->max.x, mlx->max.y, "42"))
			, perror("\e[31mERROR: mlx_new_window\e[0m\n"), -1);
	return (0);
}

int		main(void)
{
	t_mlx	mlx;

	bzero(&mlx, sizeof(mlx));
	FT_GRD(mlx_start(&mlx) == -1, -1);
	mlx_loop_hook(mlx.mlx, loop_hook, &mlx);
	mlx_hook(mlx.win, 2, 0, key_press, &mlx);
	mlx_hook(mlx.win, 3, 0, key_release, &mlx);
	mlx_hook(mlx.win, 4, 0, mouse_press, &mlx);
	mlx_hook(mlx.win, 5, 0, mouse_release, &mlx);
	mlx_hook(mlx.win, 6, 0, mouse_motion, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
