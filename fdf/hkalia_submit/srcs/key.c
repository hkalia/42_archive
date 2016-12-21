/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:05:38 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/21 11:13:58 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		key_press(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	(void)keycode;
//	ft_printf("\e[32mKey Press: Keycode:%d\e[0m\n", keycode);
	return (0);
}

int		key_release(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
//	ft_printf("\e[32mKey Release: Keycode:%d\e[0m\n", keycode);
	GRD3(keycode == 53, mlx_destroy_image(mlx->id, mlx->img.id)
		, mlx_destroy_window(mlx->id, mlx->win.id), exit(0), 0);
	return (0);
}
