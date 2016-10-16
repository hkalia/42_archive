/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 15:21:35 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/15 18:19:50 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
size_t	ft_strlen2(char *src)
{
	char	*src_cpy;

	src_cpy = src;
	if (src_cpy)
		while (*src_cpy)
			++src_cpy;
	else
		return (0);
	return (src_cpy - src);
}

char	*ft_strnew2(char *src, size_t len)
{
	char	*ret;

	if (!(ret = ft_strnew(ft_strlen(src) + len)))
	{
		ft_strdel(&src);
		return (0);
	}
	ft_strcpy(ret, src);
	ft_strdel(&src);
	return (ret);
}

int 	get_next_line(const int fd, char **line)
{
	char		*cur;
	int			ret;
	char		*x;
	static char	*storage = 0;

	if (line == 0)
		return (-1);
	if (BUFF_SIZE == 0 || BUFF_SIZE >= 7516192768ULL)
		return (-1);
	if (storage != 0)
	{
		if (!(*line = ft_strdup(storage)))
			STRDEL_RETURN(storage, -1)
		ft_strdel(&storage);
		if (!(*line = ft_strnew2(*line, BUFF_SIZE)))
			return (-1);
	}
	else
		if (!(*line = ft_strnew(BUFF_SIZE)))
			return (-1);
	if ((x = ft_strchr(*line, '\n')) != 0)
	{
		*x = '\0';
		++x;
		if (*x != '\0')
			storage = ft_strdup(x);
		return (1);
	}
	cur = *line;
	cur += ft_strlen2(*line);
	while (1)
	{
		ret = read(fd, cur, BUFF_SIZE);
		if (ret == -1)
			STRDEL_RETURN(*line, -1)
		if ((x = ft_strchr(cur, '\n')) != 0)
			break ;
		if (ret == 0)
			return (0);
		else
		{
			if (!(*line = ft_strnew2(*line, BUFF_SIZE)))
				return (-1);
			cur = *line;
			cur += ft_strlen(*line);
		}
	}
	*x = '\0';
	++x;
	if (*x != '\0')
		storage = ft_strdup(x);
	return (1);
}
