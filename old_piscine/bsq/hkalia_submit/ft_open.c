/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfriedri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 14:42:00 by mfriedri          #+#    #+#             */
/*   Updated: 2016/08/03 18:00:42 by mfriedri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		ft_stdin(void)
{
	int		fd;
	char	*buffer;
	int		ret;

	buffer = (char*)malloc(sizeof(char) * 8192);
	if (buffer == NULL)
		return (-1);
	fd = open("stdin_map", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0600);
	if (fd == -1)
		return (-1);
	while ((ret = read(0, buffer, sizeof(buffer) + 1)))
	{
		write(fd, buffer, ft_strlen(buffer));
	}
	if (close(fd) == -1)
		return (-1);
	if (buffer == NULL)
		return (-1);
	free(buffer);
	return (1);
}

int		check_special_char(char c, int y, int i)
{
	if (i == get_char_index(y))
		g_empty_sq = c;
	else if (i == get_char_index(y) + 1)
		g_blocked_sq = c;
	else if (i == get_char_index(y) + 2)
		g_fill_sq = c;
	i++;
	return (i);
}

int		close_file(char *buf, int fd)
{
	free(buf);
	if (buf == NULL || close(fd) == -1)
		return (-1);
	else
		return (0);
}

int		get_grid(int x, int y, char *file)
{
	int		fd;
	char	*buf;
	char	**grid;
	int		y2;
	int		i;

	buf = (char*)malloc(sizeof(char));
	grid = (char**)malloc(sizeof(char*) * (y + 1));
	if ((fd = open(file, O_RDONLY)) == -1 || buf == NULL)
		return (-1);
	i = 0;
	y2 = 0;
	while (read(fd, buf, 1) != 0)
	{
		if (y2 == 0)
			i = check_special_char(buf[0], y, i);
		if (buf[0] == '\n')
			i = 0;
		if (buf[0] == '\n')
			grid[y2++] = (char*)malloc(sizeof(char) * (x + 1));
		else if (y2 >= 1)
			grid[y2 - 1][i++] = buf[0];
	}
	check_grid(grid);
	return (close_file(buf, fd));
}

int		create_str(char *file)
{
	int		fd;
	char	*buf;
	int		x;
	int		y;

	buf = (char*)malloc(sizeof(char));
	fd = open(file, O_RDONLY);
	if (fd == -1 || buf == NULL)
		return (-1);
	x = 0;
	y = 0;
	while (read(fd, buf, 1) != 0)
	{
		if (buf[0] == '\n')
			y++;
		if (y == 1)
			x++;
	}
	if (buf == NULL || close(fd) == -1)
		return (-1);
	free(buf);
	g_width = --x;
	g_height = --y;
	return (((get_grid(x, y, file)) == -1) ? -1 : 1);
}
