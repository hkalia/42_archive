/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 11:35:59 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/28 14:00:28 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern uint8_t	g_ft_ls_flgs;
extern int8_t	ret;

char		*ft_ls_basename(char *path)
{
	char	*base;

	base = path;
	while (*path)
	{
		if (*path++ == '/')
			base = path;
	}
	return (base);
}

static void	handle_dirs(t_arr *dirs)
{
	t_ft_ls_file	*tmp;
	size_t			i;

	tmp = (t_ft_ls_file *)dirs->arr;
	i = 0;
	GRD2(dirs->len == 1, ft_ls_print_dir(tmp[i].path), return);
	while (i < dirs->len)
	{
		printf("\n%s:\n", tmp[i].basename);
		ft_ls_print_dir(tmp[i].path);
		++i;
	}
}

static void	handle_files(t_arr *files)
{
	t_ft_ls_file	*tmp;
	int				widths[4];
	size_t			i;

	tmp = (t_ft_ls_file *)files->arr;
	ft_bzero(widths, 4 * sizeof(int));
	i = 0;
	if (g_ft_ls_flgs & 0x1)
	{
		while (i < files->len)
			ft_ls_get_widths(widths, tmp[i++].info);
		i = 0;
		while (i < files->len)
			ft_ls_print_l(widths, tmp[i++]);
	}
	else
		printf("%s\n", tmp[i++].path);
}

int8_t		ft_ls_handle_args(int i, int argc, char **argv)
{
	t_arr			files;
	t_arr			dirs;
	t_ft_ls_file	tmp;

	GRD1(arr_init(&files, (argc - i) + 2, sizeof(t_ft_ls_file)) == -1
		, return (-1));
	GRD1(arr_init(&dirs, (argc - i) + 2, sizeof(t_ft_ls_file)) == -1
		, return (-1));
	while (i < argc)
	{
		GRD3(lstat(argv[i], &tmp.info) == -1
			, dprintf(STDERR_FILENO, "ls: %s: %s\n", argv[i++]
			, strerror(errno)), ret = -1, continue);
		GRD3((tmp.basename = ft_strdup(ft_ls_basename(argv[i]))) == 0
			, ft_ls_del(&files), ft_ls_del(&dirs), return (-1));
		GRD4((tmp.path = ft_strdup(argv[i])) == 0, free(tmp.basename)
			, ft_ls_del(&files), ft_ls_del(&dirs), return (-1));
		if (S_ISDIR(tmp.info.st_mode))
			GRD5(arr_insertat(&dirs, dirs.len, &tmp, 1) == -1, free(tmp.path)
				, free(tmp.basename), ft_ls_del(&files), ft_ls_del(&dirs)
				, return (-1));
		else
			GRD5(arr_insertat(&files, files.len, &tmp, 1) == -1, free(tmp.path)
			, free(tmp.basename), ft_ls_del(&files), ft_ls_del(&dirs)
			, return (-1));
		++i;
	}
	ft_ls_sort(&files);
	handle_files(&files);
	ft_ls_del(&files);
	ft_ls_sort(&dirs);
	handle_dirs(&dirs);
	ft_ls_del(&dirs);
	return (ret);
}
