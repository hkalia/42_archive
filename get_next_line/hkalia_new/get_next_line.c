/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 13:14:06 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/21 10:00:30 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	del(t_arr *s)
{
	size_t	i;

	i = 0;
	while (i < GNL_MAX_FD)
	{
		if (s[i].cap != 0)
			arr_dtr(&s[i]);
		++i;
	}
}

static int	final_line(const int fd, char **line, t_arr *s)
{
	GRD1((*line = ft_calloc(s[fd].len + 1, sizeof(char))) == 0, del(s), -1);
	ft_memcpy(*line, s[fd].arr, s[fd].len);
	s[fd].len = 0;
	return (1);
}

static int	assign_line(const int fd, char **line, t_arr *s, size_t src_len)
{
	GRD1((*line = ft_calloc(src_len + 1, sizeof(char))) == 0, del(s), -1);
	ft_memcpy(*line, s[fd].arr, src_len);
	arr_removeat(&s[fd], 0, src_len + 1);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_arr	s[GNL_MAX_FD] = {{0, 0, 0}};
	char			buf[BUFF_SIZE];
	uint8_t			*tmp;
	ssize_t			r;

	if (fd < 0 || fd > GNL_MAX_FD || line == 0 || BUFF_SIZE == 0)
		return (-1);
	if (s[fd].cap == 0)
		GRD1(arr_init(&s[fd], BUFF_SIZE) == -1, del(s), -1);
	while ((r = read(fd, buf, BUFF_SIZE)) != 0)
	{
		GRD1(r == -1, del(s), -1);
		GRD1(arr_insertat(&s[fd], s[fd].len, buf, r) == -1, del(s), -1);
		if ((tmp = ft_memchr(s[fd].arr, '\n', s[fd].len)) != 0)
			return (assign_line(fd, line, s, tmp - s[fd].arr));
	}
	if ((tmp = ft_memchr(s[fd].arr, '\n', s[fd].len)) != 0)
		return (assign_line(fd, line, s, tmp - s[fd].arr));
	else if (s[fd].len > 0)
		return (final_line(fd, line, s));
	arr_dtr(&s[fd]);
	return (0);
}
