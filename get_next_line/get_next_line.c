/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 15:21:35 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/14 16:49:41 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int 	get_next_line(const int fd, char **line)
{
	char	*buf;
	char	*line_cpy;
	char	*tmp;
	int		ret;

	if (fd == 0 || fd == 1 || fd == 2)
		return (-1);
	if (line == 0 || *line == 0)
		return (-1);
	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	line_cpy = *line;
	while (1)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
		{
			ft_strdel(&buf);
			return (-1);
		}
		if (read(fd, buf, 1) == 0)
			ret = 0;
		else
			ret = 1;
		tmp = ft_strchr(buf, '\n');
		if (tmp != 0)
			*tmp = '\0';
		ft_strcpy(line_cpy, buf);
		line_cpy += ft_strlen(line_cpy);
		if (tmp != 0)
			return (ret);
	}
	return (-1);
}
