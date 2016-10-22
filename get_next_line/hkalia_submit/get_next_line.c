/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 13:14:06 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/21 18:52:16 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		del(void *content, size_t content_size)
{
	if (content != 0)
		free(content);
	content_size = 0;
}

void	ft_putlst(t_list *elem)
{
	char	*str;

	str =  elem->content;
	ft_putstr(str);
	ft_putnbr(elem->content_size);
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

static int		store(t_list *cur, char **tmp)
{
	if (!(cur->content = ft_strnew2(cur->content, BUFF_SIZE)))
		return(-1);
	*tmp = cur->content;
	*tmp += ft_strlen(*tmp);
	return (0);
}

static char		*assign_line(void **cur)
{
	char	*x;
	char	*tmp;
	char	*ret;

	x = ft_strchr(*cur, '\n');
	*x = '\0';
	if (!(ret = ft_strdup(*cur)))
		return (0);
	++x;
	if (!(tmp = ft_strdup(x)))
	{
		free(ret);
		return (0);
	}
	free(*cur);
	*cur = tmp;
	if (!(*cur = ft_strnew2(*cur, BUFF_SIZE)))
	{
		free(ret);
		return (0);
	}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*head = NULL;
	t_list			*cur;
	char			*tmp;
	int				ret;

	if (fd < 0 || fd == 1 || fd == 2 || line == 0 || BUFF_SIZE == 0)
		return (-1);
	*line = 0;
	if (!(cur = fd_list(&head, fd)))
	{
		if (head)
			ft_lstdel(&head, del);
		return (-1);
	}
	tmp = cur->content;
	tmp += ft_strlen(tmp);
	while ((ret = read(fd, tmp, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
		{
			if (head)
				ft_lstdel(&head, del);
			return (-1);
		}
		else if (ft_strchr(tmp, '\n') != 0)
		{
			if (!(*line = assign_line(&(cur->content))))
			{
				if (head)
					ft_lstdel(&head, del);
				return (-1);
			}
			return (1);
		}
		else if (store(cur, &tmp) == -1)
		{
			if (head)
				ft_lstdel(&head, del);
			return (-1);
		}
	}
	if (ft_strlen(cur->content) != 0)
	{
		if (ft_strchr(tmp, '\n') != 0)
		{
			if (!(*line = assign_line(&(cur->content))))
			{
				if (head)
					ft_lstdel(&head, del);
				return (-1);
			}
			return (1);
		}
		else
		{
			if (!(*line = ft_strdup(cur->content)))
			{
				if (head)
					ft_lstdel(&head, del);
				return (-1);
			}
			free(cur->content);
			cur->content = 0;
			return(1);
		}
	}
	return (0);
}
