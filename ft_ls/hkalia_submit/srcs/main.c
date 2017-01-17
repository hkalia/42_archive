/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:28:07 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/17 14:42:32 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		dirent_cmpr(const void *a, const void *b)
{
	if (g_ft_ls_flgs & 0x8)
	{
		
	}
	return (ft_strcmp((*(struct dirent **)a)->d_name
			, (*(struct dirent **)b)->d_name));
}

int8_t	printer(char *path)
{
	DIR				*dirp;
	struct dirent	*dp;
	struct dirent	**tmp;
	size_t			i;
	t_arr			dp_arr;

	GRD(arr_init(&dp_arr, 8) == -1, -1);
	GRD((dirp = opendir(path)) == 0, -1);
	i = 0;
	while ((dp = readdir(dirp)) != 0)
	{
		GRD2(arr_insertat(&dp_arr, i * sizeof(dp), &dp, sizeof(dp)) == -1
			, closedir(dirp), arr_dtr(&dp_arr), -1);
		++i;
	}
	qsort(dp_arr.arr, dp_arr.len / sizeof(struct dirent *)
			, sizeof(struct dirent *), dirent_cmpr);
	tmp = (struct dirent **)dp_arr.arr;
	if (g_ft_ls_flgs & 0x8)
	{
		i = dp_arr.len / sizeof(struct dirent *);
		while (--i)
		{
			if (g_ft_ls_flgs & 0x4)
				ft_printf("%s\n", tmp[i]->d_name);
			else
			{
				if (tmp[i]->d_name[0] != '.')
					ft_printf("%s\n", tmp[i]->d_name);
			}
		}
		if (g_ft_ls_flgs & 0x4)
			ft_printf("%s\n", tmp[i]->d_name);
		else
		{
			if (tmp[i]->d_name[0] != '.')
				ft_printf("%s\n", tmp[i]->d_name);
		}
	}
	else
	{
		i = 0;
		while (i * sizeof(struct dirent *) < dp_arr.len)
		{
			if (g_ft_ls_flgs & 0x4)
				ft_printf("%s\n", tmp[i]->d_name);
			else
			{
				if (tmp[i]->d_name[0] != '.')
					ft_printf("%s\n", tmp[i]->d_name);
			}
			++i;
		}
	}
	closedir(dirp);
	arr_dtr(&dp_arr);
	return (0);
}

int8_t	parser(int argc, char **argv)
{
	int		i;
	size_t	j;

	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		if (argv[i][1] == '-')
			break ;
		j = 1;
		while (argv[i][j] != 0)
		{
			if (argv[i][j] == 'l')
				g_ft_ls_flgs |= 0x1;
			else if (argv[i][j] == 'R')
				g_ft_ls_flgs |= 0x2;
			else if (argv[i][j] == 'a')
				g_ft_ls_flgs |= 0x4;
			else if (argv[i][j] == 'r')
				g_ft_ls_flgs |= 0x8;
			else if (argv[i][j] == 't')
				g_ft_ls_flgs |= 0x10;
			else
			{
				fprintf(stderr, "usage: ls [-lRart] [file ...]\n");
				return (-1);
			}
			++j;
		}
		++i;
	}
	printer(".");
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		GRD(printer(".") == -1, -1);
	else if (argc > 1)
		GRD(parser(argc, argv) == -1, -1);
	else
	{
		perror("ft_ls");
		return(-1);
	}
	return (0);
}
