/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 13:14:06 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/20 17:10:14 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gnl.h>

static void		gnl_del(t_arr **s)
{
	size_t	i;

	i = 0;
	while (i < GNL_MAX_FD)
	{
		if (s[i] != 0)
			arr_dtr(s[i]);
		++i;
	}
}

int				gnl(const int fd, char **line)
{
	static t_arr	*s[GNL_MAX_FD] = {0};
	char			*buf[GNL_BUFF_SIZE];
	ssize_t			r;

	if (fd < 0 || fd > GNL_MAX_FD || line == 0 || GNL_BUFF_SIZE == 0)
		return (-1);
	if (s[fd] == 0)
	{
		GRD1((s[fd] = ft_calloc(1, sizeof(t_arr))) == 0, gnl_del(s), -1);
		GRD1(arr_init(s[fd], GNL_BUFF_SIZE) == -1, gnl_del(s), -1);
	}
	while ((r = read(fd, buf, GNL_BUFF_SIZE)) != 0)
	{
		GRD1(r == -1, gnl_del(s), -1);
		if (ft_memchr(buf, '\n', r) != 0)
		{

		arr_insertat(s[fd], s[fd]->len, buf, r);
	}
	return (1);
}
