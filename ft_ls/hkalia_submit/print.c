/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 12:26:28 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/28 13:03:16 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

static void	print_lnk(char *path)
{
	char	tmp[PATH_MAX + 1];

	ft_bzero(tmp, PATH_MAX + 1);
	readlink(path, tmp, PATH_MAX);
	printf(" -> %s", tmp);
}

static void	print_rwx(mode_t mode)
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

static void	print_type(mode_t mode)
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

void		ft_ls_get_widths(int *widths, struct stat info)
{
	widths[0] = MAX(widths[0], (int)ft_nbrlen(info.st_nlink));
	widths[1] = MAX(widths[1], (int)ft_strlen(getpwuid(info.st_uid)
					->pw_name));
	widths[2] = MAX(widths[2], (int)ft_strlen(getgrgid(info.st_gid)
					->gr_name));
	widths[3] = MAX(widths[3], (int)ft_nbrlen(info.st_size));
}

void		ft_ls_print_l(int *widths, t_ft_ls_file file)
{
	long	diff;
	char	*tmp;

	diff = time(0) - file.info.st_mtimespec.tv_sec;
	tmp = ctime(&file.info.st_mtimespec.tv_sec);
	print_type(file.info.st_mode);
	print_rwx(file.info.st_mode);
	printf(listxattr(file.path, 0, 0, XATTR_NOFOLLOW) > 0 ? "@" : " ");
	printf(" %*d %-*s  %-*s  %*lld %.6s"
	, widths[0], file.info.st_nlink
	, widths[1], getpwuid(file.info.st_uid)->pw_name
	, widths[2], getgrgid(file.info.st_gid)->gr_name
	, widths[3], file.info.st_size, &tmp[4]);
	if (diff > 15552000 || diff < -15552000)
		printf("  %.4s", &tmp[20]);
	else
		printf(" %.5s", &tmp[11]);
	printf(" %s", file.basename);
	if (S_ISLNK(file.info.st_mode))
		print_lnk(file.path);
	printf("\n");
}
