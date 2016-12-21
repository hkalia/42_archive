/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:16:04 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/21 11:40:27 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <strings.h>

void			square(t_mlx *mlx, int color, t_ixyxy src)
{
	line(mlx, color, (t_ixyxy){src.x0, src.y0, src.x1, src.y0});
	line(mlx, color, (t_ixyxy){src.x1, src.y0, src.x1, src.y1});
	line(mlx, color, (t_ixyxy){src.x1, src.y1, src.x0, src.y1});
	line(mlx, color, (t_ixyxy){src.x0, src.y1, src.x0, src.y0});
}

static int8_t	mlx_start(t_mlx *mlx)
{
	GRD1(!(mlx->id = mlx_init()), perror("\e[31mERROR: mlx_init\e[0m\n"), -1);
	mlx->win.max.x = 640;
	mlx->win.max.y = 480;
	GRD1(!(mlx->win.id = mlx_new_window(mlx->id, mlx->win.max.x, mlx->win.max.y
		, "42")), perror("\e[31mERROR: mlx_new_window\e[0m\n"), -1);
	GRD1((mlx->img.id = mlx_new_image(mlx->id, mlx->win.max.x, mlx->win.max.y))
		== 0, perror("\e[31mERROR: mlx_new_image\e[0m\n"), -1);
	mlx->img.img = mlx_get_data_addr(mlx->img.id, &mlx->img.bpp, &mlx->img.ln
									, &mlx->img.end);
	mlx->img.bpp /= 8;
	return (0);
}

static int8_t	reader(char *filename, t_mlx *mlx)
{
	int		fd;
	int		r;
	char	*line;

	GRD1((fd = open(filename, O_RDONLY) == -1)
		, perror("\e[31mERROR: open\e[0m\n"), -1);
	arr_init(&mlx->src, 100);
	while ((r = gnl(fd, &line)) == 1)
	{
		GRD1(arr_insertat(&mlx->src, mlx->src.len, line, ft_strlen(line)) == -1
			, perror("\e[31mERROR: arr_insertat\e[0m\n"), -1);
		free(line);
	}
	GRD1(r == -1, perror("\e[31mERROR: gnl\e[0m\n"), -1);
	return (0);
}

int				main(int argc, char **argv)
{
	t_mlx	mlx;

	GRD1(argc != 2, ft_printf("Usage : %s <filename> [ case_size z_size ]"
		, argv[0]), -1);
	ft_bzero(&mlx, sizeof(mlx));
	GRD1(reader(argv[1], &mlx) == -1, perror("\e[31mERROR: reader\e[0m\n"), -1);
	GRD(mlx_start(&mlx) == -1, -1);
	mlx_hook(mlx.win.id, 2, 0, key_press, &mlx);
	mlx_hook(mlx.win.id, 3, 0, key_release, &mlx);
	mlx_hook(mlx.win.id, 4, 0, mouse_press, &mlx);
	mlx_hook(mlx.win.id, 5, 0, mouse_release, &mlx);
	mlx_hook(mlx.win.id, 6, 0, mouse_motion, &mlx);
	mlx_loop(mlx.id);
	return (0);
}
