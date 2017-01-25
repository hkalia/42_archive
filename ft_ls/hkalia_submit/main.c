/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:28:07 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/25 14:26:51 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

uint8_t	g_ft_ls_flgs = 0;

void	lhandler_3(char *path)
{
	char	tmp[PATH_MAX + 1];

	ft_bzero(tmp, PATH_MAX + 1);
	readlink(path, tmp, PATH_MAX);
	printf(" -> %s", tmp);
}

void	lhandler_2(mode_t mode)
{
	printf((mode & S_IRUSR) ? "r" : "-");
	printf((mode & S_IWUSR) ? "w" : "-");
	if (mode & S_ISUID)
		printf((mode & S_IXUSR) ? "s" : "S");
	else
		printf((mode & S_IXUSR) ? "x" : "-");
	printf((mode & S_IRGRP) ? "r" : "-");
	printf((mode & S_IWGRP) ? "w" : "-");
	if (mode & S_ISGID)
		printf((mode & S_IXGRP) ? "s" : "S");
	else
		printf((mode & S_IXGRP) ? "x" : "-");
	printf((mode & S_IROTH) ? "r" : "-");
	printf((mode & S_IWOTH) ? "w" : "-");
	if (mode & S_ISVTX)
		printf((mode & S_IXUSR) ? "t" : "T");
	else
		printf((mode & S_IXOTH) ? "x" : "-");
}

void	lhandler_1(mode_t mode)
{
	char		c;

	if (S_ISBLK(mode))
		c = 'b';
	else if (S_ISCHR(mode))
		c = 'c';
	else if (S_ISDIR(mode))
		c = 'd';
	else if (S_ISLNK(mode))
		c = 'l';
	else if (S_ISSOCK(mode))
		c = 's';
	else if (S_ISFIFO(mode))
		c = 'p';
	else if (S_ISREG(mode))
		c = '-';
	else
		c = '-';
	printf("%c", c);
}

int8_t	lhandler(t_arr *files)
{
	t_file		*tmp;
	int			widths[5];
	long long	blks;
	size_t		i;

	tmp = (t_file *)files->arr;
	ft_bzero(widths, 5 * sizeof(int));
	blks = 0;
	i = 0;
	while (i < files->len)
	{
		widths[0] = MAX(widths[0], (int)ft_nbrlen(tmp[i].info.st_nlink));
		widths[1] = MAX(widths[1], (int)ft_strlen(getpwuid(tmp[i].info.st_uid)
													->pw_name));
		widths[2] = MAX(widths[2], (int)ft_strlen(getgrgid(tmp[i].info.st_gid)
													->gr_name));
		widths[3] = MAX(widths[3], (int)ft_nbrlen(tmp[i].info.st_size));
		blks += tmp[i].info.st_blocks;
		++i;
	}
	printf("total %lld\n", blks);
	i = 0;
	while (i < files->len)
	{
		lhandler_1(tmp[i].info.st_mode);
		lhandler_2(tmp[i].info.st_mode);
		printf(listxattr(tmp[i].path, 0, 0, XATTR_NOFOLLOW) > 0 ? "@" : " ");
		printf(" %*d", widths[0], tmp[i].info.st_nlink);
		printf(" %-*s ", widths[1], getpwuid(tmp[i].info.st_uid)->pw_name);
		printf(" %-*s ", widths[2], getgrgid(tmp[i].info.st_gid)->gr_name);
		printf(" %*lld", widths[3], tmp[i].info.st_size);
		printf(" %.12s", &ctime(&tmp[i].info.st_mtimespec.tv_sec)[4]);
		printf(" %s", tmp[i].basename);
		if (S_ISLNK(tmp[i].info.st_mode))
			lhandler_3(tmp[i].path);
		printf("\n");
		++i;
	}
	return (0);
}

int		compare(const void *a, const void *b, size_t elm)
{
	(void)elm;
	return (ft_strcmp(((t_file *)a)->basename, ((t_file *)b)->basename));
}

int		time_compare(const void *a, const void *b, size_t elm)
{
	(void)elm;
	return (((t_file *)b)->info.st_mtimespec.tv_sec
			- ((t_file *)a)->info.st_mtimespec.tv_sec);
}

static void	del(t_arr *files)
{
	t_file	*tmp;
	size_t	i;

	tmp = (t_file *)files->arr;
	i = 0;
	while (i < files->len)
	{
		free(tmp[i].path);
		free(tmp[i].basename);
		++i;
	}
	arr_dtr(files);
}

int8_t	open_dir(t_arr *files, char *path)
{
	DIR				*dirp;
	struct dirent	*dp;
	t_file			tmp;

	GRD((dirp = opendir(path)) == 0, -1);
	GRD(arr_init(files, 10, sizeof(t_file)) == -1, -1);
	while ((dp = readdir(dirp)) != 0)
	{
		asprintf(&tmp.path, "%s/%s", path, dp->d_name);
		tmp.basename = ft_strdup(dp->d_name);
		lstat(tmp.path, &tmp.info);
		GRD2(arr_insertat(files, files->len, &tmp, 1) == -1, del(files)
			, closedir(dirp), -1);
	}
	closedir(dirp);
	return (0);
}

int8_t	print_dir(char *path)
{
	t_arr			files;
	t_file			*tmp;
	size_t			i;

	GRD(open_dir(&files, path) == -1, -1);
	tmp = (t_file *)files.arr;
	if (g_ft_ls_flgs & 0x10)
		arr_qsort(&files, time_compare);
	else
		arr_qsort(&files, compare);
	if (g_ft_ls_flgs & 0x8)
		arr_reverse(&files);
	if (g_ft_ls_flgs & 0x1)
		lhandler(&files);
	else
	{
		i = 0;
		while (i < files.len)
			printf("%s\n", tmp[i++].basename);
	}
	if (g_ft_ls_flgs & 0x2)
	{
		i = 0;
		while (i < files.len)
		{
			if (S_ISDIR(tmp[i].info.st_mode)
				&& ft_strcmp(tmp[i].basename, ".") != 0
				&& ft_strcmp(tmp[i].basename, "..") != 0)
			{
				printf("\n%s:\n", path);
				GRD1(print_dir(path) == -1, del(&files), -1);
			}
			++i;
		}
	}
	del(&files);
	return (0);
}

int		compare_1(const void *a, const void *b, size_t elm)
{
	(void)elm;
	return (ft_strcmp((*(char **)a), (*(char **)b)));
}

int8_t	handle_args(int i, int argc, char **argv)
{
	t_arr	names;
	size_t	j;
	char	**tmp;

	GRD(arr_init(&names, 4, sizeof(char *)) == -1, -1);
	while (i < argc)
	{
		GRD1(arr_insertat(&names, names.len, &argv[i], 1) == -1
			, arr_dtr(&names), -1);
		++i;
	}
	arr_qsort(&names, compare_1);
	tmp = (char **)names.arr;
	j = 0;
	while (j < names.len)
	{
		printf("%s:\n", tmp[j]);
		GRD(print_dir(tmp[j]) == -1, -1);
		if (names.len - j != 1)
			printf("\n");
		++j;
	}
	return (0);
}

char	*get_parent(char *path)
{
	size_t	len;

	if ((len = (ft_strrchr(path, '/') - path)) <= 0)
		return (ft_strdup("."));
	else
		return (ft_strndup(path, len));
}

int8_t	handle_one(char *path)
{
	char			*parent;
	t_arr			files;

	GRD((parent = get_parent(path)) == 0, -1);
	printf("%s\n", parent);
	GRD1(open_dir(&files, parent) == -1, free(parent), -1);
	free(parent);
	del(&files);
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
		j = 0;
		while (argv[i][++j] != 0)
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
			else if (argv[i][j] == '1');
			else
				return (-1);
		}
		++i;
	}
	if (i < argc)
	{
		if (argc - i == 1)
			GRD(handle_one(argv[i]) == -1, -1);
		else
			GRD(handle_args(i, argc, argv) == -1, -1);
	}
	else
		GRD(print_dir(".") == -1, -1);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		GRD(print_dir(".") == -1, -1);
	else if (argc > 1)
		GRD(parser(argc, argv) == -1, -1);
	else
	{
		perror("ft_ls");
		return(-1);
	}
	return (0);
}
