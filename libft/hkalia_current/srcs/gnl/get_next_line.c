/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 13:14:06 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/25 16:10:51 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		del(void *content, size_t content_size)
{
	if (content != 0)
		free(content);
	content_size = 0;
}

static t_list	*fd_list(t_list **head, int fd)
{
	t_list	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (fd == (int)tmp->content_size)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = ft_lstnew(0, 0)))
		return (0);
	if (!(tmp->content = ft_strnew(BUFF_SIZE)))
	{
		free(tmp);
		return (0);
	}
	tmp->content_size = fd;
	tmp->next = *head;
	*head = tmp;
	return (tmp);
}

static int		assign_line(t_list **cur, int *ret, char **line)
{
	char	*cpy;
	char	*tmp;
	size_t	i;

	cpy = (*cur)->content;
	i = 0;
	tmp = 0;
	if (*ret == 0 && ft_strlen(cpy) == 0)
		return (0);
	while (cpy && cpy[i] && cpy[i] != '\n')
		++i;
	if (!(*line = ft_strndup(cpy, i)))
		return (-1);
	if (cpy[i] == '\n')
	{
		if (!(tmp = ft_strdup(cpy + i + 1)))
			STR_GUARD(&(*line));
		tmp = ft_strnew2(tmp, BUFF_SIZE);
	}
	free((*cur)->content);
	(*cur)->content = tmp;
	*ret = 1;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*head = NULL;
	t_list			*cur;
	char			*buf;
	int				ret;

	if (fd < 0 || line == 0 || BUFF_SIZE == 0)
		return (-1);
	*line = 0;
	IF_LST_GUARD(!(cur = fd_list(&head, fd)));
	buf = cur->content;
	buf += ft_strlen(buf);
	LST_GUARD(read(fd, buf, 0) == -1);
	while ((ft_strchr(buf, '\n') == 0) && (ret = read(fd, buf, BUFF_SIZE) != 0))
	{
		LST_GUARD(ret == -1);
		LST_GUARD(!(cur->content = ft_strnew2(cur->content, BUFF_SIZE)));
		buf = cur->content;
		buf += ft_strlen(buf);
	}
	LST_GUARD(assign_line(&cur, &ret, &(*line)) == -1);
	return (ret);
}
