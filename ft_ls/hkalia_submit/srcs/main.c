/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:28:07 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/23 15:05:40 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

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

int8_t	lhandler(t_arr *files, char *path)
{
	t_file		*tmp;
	char		*tmp_p;
	int			widths[5];
	long long	blks;
	size_t		i;

	(void)path;
	tmp = (t_file *)files->arr;
	ft_bzero(widths, 5 * sizeof(int));
	blks = 0;
	i = 0;
	while (i < files->len)
	{
		widths[0] = MAX(widths[0], (int)ft_nbrlen(tmp[i].detail.st_nlink));
		widths[1] = MAX(widths[1], (int)ft_strlen(getpwuid(tmp[i].detail.st_uid)
													->pw_name));
		widths[2] = MAX(widths[2], (int)ft_strlen(getgrgid(tmp[i].detail.st_gid)
													->gr_name));
		widths[3] = MAX(widths[3], (int)ft_nbrlen(tmp[i].detail.st_size));
		blks += tmp[i].detail.st_blocks;
		++i;
	}
	printf("total %lld\n", blks);
	i = 0;
	while (i < files->len)
	{
		lhandler_1(tmp[i].detail.st_mode);
		lhandler_2(tmp[i].detail.st_mode);
		asprintf(&tmp_p, "%s/%s", path, tmp[i].name);
		printf(listxattr(tmp_p, 0, 0, XATTR_NOFOLLOW) > 0 ? "@" : " ");
		printf(" %*d", widths[0], tmp[i].detail.st_nlink);
		printf(" %-*s ", widths[1], getpwuid(tmp[i].detail.st_uid)->pw_name);
		printf(" %-*s ", widths[2], getgrgid(tmp[i].detail.st_gid)->gr_name);
		printf(" %*lld", widths[3], tmp[i].detail.st_size);
		printf(" %.12s", &ctime(&tmp[i].detail.st_mtimespec.tv_sec)[4]);
		printf(" %s", tmp[i].name);
		if (S_ISLNK(tmp[i].detail.st_mode))
			lhandler_3(tmp_p);
		printf("\n");
		free(tmp_p);
		++i;
	}
	return (0);
}

int		compare(const void *a, const void *b, size_t elm)
{
	(void)elm;
	return (ft_strcmp(((t_file *)a)->name, ((t_file *)b)->name));
}

int		time_compare(const void *a, const void *b, size_t elm)
{
	(void)elm;
	return (((t_file *)b)->detail.st_mtimespec.tv_sec
			- ((t_file *)a)->detail.st_mtimespec.tv_sec);
}

int8_t	assign(t_arr *files, char *path, char *name)
{
	char	*tmp;
	t_file	tmp_s;

	tmp_s.name = name;
	asprintf(&tmp, "%s/%s", path, name);
	lstat(tmp, &tmp_s.detail);
	GRD1(arr_insertat(files, files->len, &tmp_s, 1) == -1, free(tmp), -1);
	free(tmp);
	return (0);
}

int8_t	printer(char *path)
{
	DIR				*dirp;
	struct dirent	*dp;
	t_arr			files;
	size_t			i;

	GRD((dirp = opendir(path)) == 0, -1);
	GRD(arr_init(&files, 10, sizeof(t_file)) == -1, -1);
	while ((dp = readdir(dirp)) != 0)
	{
		if (dp->d_name[0] == '.' && !(g_ft_ls_flgs & 0x4))
			continue;
		GRD2(assign(&files, path, dp->d_name) == -1, closedir(dirp)
			, arr_dtr(&files), -1);
	}
	if (g_ft_ls_flgs & 0x10)
		arr_qsort(&files, time_compare);
	else
		arr_qsort(&files, compare);
	if (g_ft_ls_flgs & 0x8)
		arr_reverse(&files);
	if (g_ft_ls_flgs & 0x1)
		lhandler(&files, path);
	else
	{
		i = 0;
		while (i < files.len)
		{
			printf("%s\n", ((t_file *)ARR_INDEX(&files, i))->name);
			++i;
		}
	}
	closedir(dirp);
	arr_dtr(&files);
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
				return (-1);
			++j;
		}
		++i;
	}
	if (i < argc)
		while (i < argc)
		{
			printer(argv[i]);
			++i;
		}
	else
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
