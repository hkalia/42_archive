/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:38:54 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/28 12:42:20 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern uint8_t g_ft_ls_flgs;

void	ft_ls_del(t_arr *files)
{
	t_ft_ls_file	*tmp;
	size_t			i;

	tmp = (t_ft_ls_file *)files->arr;
	i = 0;
	while (i < files->len)
	{
		free(tmp[i].path);
		free(tmp[i].basename);
		++i;
	}
	arr_dtr(files);
}

static int	compare(const void *a, const void *b, size_t elm)
{
	(void)elm;
	return (ft_strcmp(((t_ft_ls_file *)a)->basename
			, ((t_ft_ls_file *)b)->basename));
}

static int	time_compare(const void *a, const void *b, size_t elm)
{
	(void)elm;
	return (((t_ft_ls_file *)b)->info.st_mtimespec.tv_sec
			- ((t_ft_ls_file *)a)->info.st_mtimespec.tv_sec);
}

void		ft_ls_sort(t_arr *files)
{
	if (g_ft_ls_flgs & 0x10)
	arr_qsort(files, time_compare);
	else
	arr_qsort(files, compare);
	if (g_ft_ls_flgs & 0x8)
	arr_reverse(files);
}
