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
	if (src_cpy != 0)
		while (*src_cpy)
			++src_cpy;
	else
		return (0);
	return (src_cpy - src);
}

char	*ft_strnew2(char *src, size_t len)
{
	char	*ret;

	if (src != 0 && *src != '\0')
	{
		if (!(ret = ft_strnew(ft_strlen2(src) + len)))
		{
			ft_strdel(&src);
			return (0);
		}
		ft_strcpy(ret, src);
		ft_strdel(&src);
	}
	else
		if (!(ret = ft_strnew(len)))
			return (0);
	return (ret);
}

int		*ft_nbrstrnew(int *src, int *size, int len)
{
	int		*ret;
	int		i;

	i = 0;
	if (!(ret = (int *)malloc(sizeof(int) * (*size + len))))
		return (0);
	while (i < *size)
	{
		ret[i] = src[i];
		++i;
	}
	free(src);
	len = len + *size;
	while (i < len)
	{
		ret[i] = 0;
		++i;
	}
	*size = len;
	return (ret);
}

int		ft_tbllen(char	**src)
{
	int		i;

	i = 0;
	if (src != 0)
		while (src[i])
			++i;
	else
		return (0);
	return (i);
}

void	ft_tblcpy(char **dst, char **src)
{
	int		i;
	int		j;

	i = 0;
	while (src[i])
	{
		j = 0;
		while (src[i][j])
		{
			dst[i][j] = src[i][j];
			++j;
		}
		++i;
	}
}

char	**ft_tblnew3(char **src, int len)
{
	char	**ret;
	int		size;
	int		i;

	size = ft_tbllen(src);
	if (!(ret = (char **)malloc(sizeof(char *) * (size + len + 1))))
		return (0);
	if (size > 0)
	{
		ft_tblcpy(ret, src);
		i = size;
		len = len + size;
	}
	else
		i = 0;
	while (i <= len)
	{
		ret[i] = 0;
		++i;
	}
	return (ret);
}

int		new_fd(int fd, t_info *storage)
{
	if (!(storage->fd_arr = ft_nbrstrnew(storage->fd_arr, &(storage->fd_arr_size), 1)))
	{
		if (storage->fd_arr_size != 0)
		{
			free(storage->fd_arr);
			ft_tbldel(storage->tbl);
		}
		return (-1);
	}
	storage->fd_arr[(storage->fd_arr_size) - 1] = fd;
	if (!(storage->tbl = ft_tblnew3(storage->tbl, 1)))
	{
		if (storage->fd_arr_size != 0)
		{
			free(storage->fd_arr);
			ft_tbldel(storage->tbl);
		}
		return (-1);
	}
	return (0);
}

char	*assign_line(char *cur)
{
	char	*tmp;
	char	*ret;

	tmp = ft_strchr(cur, '\n');
	if (tmp != 0)
		*tmp = '\0';
	if (!(ret = ft_strdup(cur)))
		return (0);
	if (tmp != 0)
		*tmp = '\n';
	return (ret);
}

int		get_next_line(const int	fd, char **line)
{
	static t_info	storage;
	int				i;
	char			*cur;
	char			*tmp;
	char			buf[BUFF_SIZE];
	int				ret;

	if (fd < 0 || line == 0 || BUFF_SIZE == 0)
		return (-1);
	i = 0;
	cur = 0;
	while (i < storage.fd_arr_size)
	{
		if (storage.fd_arr[i] == fd)
			cur = storage.tbl[i];
		++i;
	}
	if (cur == 0)
	{
		if (new_fd(fd, &storage) == -1)
		{
			*line = 0;
			return(-1);
		}
		cur = storage.tbl[ft_tbllen(storage.tbl)];
	}
	else
	{
		if (ft_strchr(cur, '\n') != 0)
		{
			if (!(*line = assign_line(cur)))
			{
				free(storage.fd_arr);
				ft_tbldel(storage.tbl);
				*line = 0;
				return (-1);
			}
			while (*cur != '\n')
				++cur;
			storage.tbl[i] =  cur;
			return (1);
		}
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
		{
			free(storage.fd_arr);
			ft_tbldel(storage.tbl);
			*line = 0;
			return (-1);
		}
		if (!(storage.tbl[i] = ft_strnew2(storage.tbl[i], BUFF_SIZE)))
		{
			free(storage.fd_arr);
			ft_tbldel(storage.tbl);
			*line = 0;
			return (-1);
		}
		ft_strncpy(&storage.tbl[i][ft_strlen2(storage.tbl[i])], buf, BUFF_SIZE);
		if (ft_strchr(storage.tbl[i], '\n') != 0)
		{
			if (!(*line = assign_line(storage.tbl[i])))
			{
				free(storage.fd_arr);
				ft_tbldel(storage.tbl);
				*line = 0;
				return (-1);
			}
			tmp = storage.tbl[i];
			while (*tmp != '\n')
				++tmp;
			++tmp;
			if (!(tmp = ft_strnew2(tmp, 0)))
			{
				free(storage.fd_arr);
				ft_tbldel(storage.tbl);
				*line = 0;
				return (-1);
			}
			free(storage.tbl[i]);
			storage.tbl[i] = tmp;
			return (1);
		}
	}
	if (storage.tbl[i] != 0)
	{
		if (ft_strchr(storage.tbl[i], '\n') != 0)
		{
			if (!(*line = assign_line(storage.tbl[i])))
			{
				free(storage.fd_arr);
				ft_tbldel(storage.tbl);
				*line = 0;
				return (-1);
			}
			cur = storage.tbl[i];
			while (*cur != '\n')
				++cur;
			storage.tbl[i] =  cur;
			return (1);
		}
		else
		{
			if (!(*line = assign_line(storage.tbl[i])))
			{
				free(storage.fd_arr);
				ft_tbldel(storage.tbl);
				*line = 0;
				return (-1);
			}
			free(storage.tbl[i]);
			storage.tbl[i] = 0;
			return (1);
		}
	}
	return (0);
}




























