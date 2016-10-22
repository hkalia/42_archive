/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 13:14:06 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/20 14:19:50 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*fd_lst(t_list **head, int fd)
{
	cha
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*head = NULL;
	t_list			*cur;
	char			*buf;
	int				ret;

	if (fd < 0 || line == 0 || BUFF_SIZE == 0)
		return (-1);
	while (ret = read(fd, buf, BUFF_SIZE))
	{
		if (ret == -1)
			break ;
	}
	return (0);
}
