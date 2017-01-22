/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:28:07 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/21 17:50:10 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		compare(const void *a, const void *b, size_t elm)
{
	(void)elm;
	return (ft_strcmp((*(struct dirent **)a)->d_name
			, (*(struct dirent **)b)->d_name));
}

int		time_compare(const void *a, const void *b, size_t elm, void *thunk)
{
	char		*path;
	char		*tmp;
	struct stat	tmp_s;
	time_t		a_t;
	time_t		b_t;

	(void)elm;
	path = (char *)thunk;
	asprintf(&tmp, "%s/%s", path, (*(struct dirent **)a)->d_name);
	lstat(tmp, &tmp_s);
	a_t = tmp_s.st_mtimespec.tv_sec;
	free(tmp);
	asprintf(&tmp, "%s/%s", path, (*(struct dirent **)b)->d_name);
	lstat(tmp, &tmp_s);
	b_t = tmp_s.st_mtimespec.tv_sec;
	free(tmp);
	return (b_t - a_t);
}

int8_t	lhandler(char *path, t_arr *dp_arr)
{
	char		*tmp;
	struct stat	tmp_s;
	size_t		i;

	i = 0;
	while (i < dp_arr->len)
	{
		asprintf(&tmp, "%s/%s", path
				, (*(struct dirent **)ARR_INDEX(dp_arr, i))->d_name);
		lstat(tmp, &tmp_s);
		if (S_ISBLK(tmp_s.st_mode) != 0)
			printf("b");
		else if (S_ISCHR(tmp_s.st_mode) != 0)
			printf("c");
		else if (S_ISDIR(tmp_s.st_mode) != 0)
			printf("d");
		else if (S_ISLNK(tmp_s.st_mode) != 0)
			printf("l");
		else if (S_ISSOCK(tmp_s.st_mode) != 0)
			printf("s");
		else if (S_ISFIFO(tmp_s.st_mode) != 0)
			printf("p");
		else if (S_ISREG(tmp_s.st_mode) != 0)
			printf("-");
		printf("%c", tmp_s.st_mode & S_IRUSR ? 'r' : '-');
		printf("%c", tmp_s.st_mode & S_IWUSR ? 'w' : '-');
		if (tmp_s.st_mode & S_IXUSR)
		{
			if (tmp_s.st_mode & S_ISUID)
				printf("s");
			else
				printf("x");
		}
		else
		{
			if (tmp_s.st_mode & S_ISUID)
				printf("S");
			else
				printf("-");
		}
		printf("%c", tmp_s.st_mode & S_IRGRP ? 'r' : '-');
		printf("%c", tmp_s.st_mode & S_IWGRP ? 'w' : '-');
		if (tmp_s.st_mode & S_IXGRP)
		{
			if (tmp_s.st_mode & S_ISGID)
				printf("s");
			else
				printf("x");
		}
		else
		{
			if (tmp_s.st_mode & S_ISGID)
				printf("S");
			else
				printf("-");
		}
		printf("%c", tmp_s.st_mode & S_IROTH ? 'r' : '-');
		printf("%c", tmp_s.st_mode & S_IWOTH ? 'w' : '-');
		if (tmp_s.st_mode & S_IXOTH)
		{
			if (tmp_s.st_mode & S_ISVTX)
				printf("t");
			else
				printf("x");
		}
		else
		{
			if (tmp_s.st_mode & S_ISVTX)
				printf("T");
			else
				printf("-");
		}
		printf(" %s\n", (*(struct dirent **)ARR_INDEX(dp_arr, i))->d_name);
		free(tmp);
		++i;
	}

	return (0);
}

int8_t	printer(char *path)
{
	DIR				*dirp;
	struct dirent	*dp;
	t_arr			dp_arr;
	size_t			i;

	GRD((dirp = opendir(path)) == 0, -1);
	GRD(arr_init(&dp_arr, 10, sizeof(dp)) == -1, -1);
	while ((dp = readdir(dirp)) != 0)
	{
		if (dp->d_name[0] == '.')
		{
			if (g_ft_ls_flgs & 0x4)
				GRD2(arr_insertat(&dp_arr, dp_arr.len, &dp, 1) == -1
					, closedir(dirp), arr_dtr(&dp_arr), -1);
		}
		else
			GRD2(arr_insertat(&dp_arr, dp_arr.len, &dp, 1) == -1, closedir(dirp)
				, arr_dtr(&dp_arr), -1);
	}
	if (g_ft_ls_flgs & 0x10)
		arr_qsort_r(&dp_arr, path, time_compare);
	else
		arr_qsort(&dp_arr, compare);
	if (g_ft_ls_flgs & 0x8)
		arr_reverse(&dp_arr);
	if (g_ft_ls_flgs & 0x1)
		lhandler(path, &dp_arr);
	else
	{
		i = 0;
		while (i < dp_arr.len)
		{
			printf("%s\n", (*(struct dirent **)ARR_INDEX(&dp_arr, i))->d_name);
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
				return (-1);
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