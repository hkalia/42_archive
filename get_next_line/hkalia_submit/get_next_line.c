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

char	*ft_strnew2(char *src, size_t len)
{
	char	*ret;

	if (src != 0 && *src != '\0')
	{
		if (!(ret = ft_strnew(ft_strlen(src) + len)))
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

static t_list	*fd_list(t_list **list, int fd)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (fd == (int)tmp->content_size)
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*head = NULL;
	t_list			*cur;
	char			*tmp;
	char			*tmp1;
	int				ret;

	if (fd < 0 || fd == 1 || fd == 2 || line == 0 || BUFF_SIZE == 0)
		return (-1);
	if (!(cur = fd_list(&head, fd)))
	{
		if (!(cur = ft_lstnew(0, 0)))
		{
			if (head)
				ft_lstdel(&head, del);
			return (-1);
		}
		if (!(cur->content = ft_strnew(BUFF_SIZE)))
		{
			if (head)
				ft_lstdel(&head, del);
			return (-1);
		}
		cur->content_size = fd;
		ft_lstadd(&head, cur);
	}
	tmp = cur->content;
	while ((ret = read(fd, tmp, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
		{
			if (head)
				ft_lstdel(&head, del);
			return (-1);
		}
		else if ((tmp1 = ft_strchr(tmp, '\n')) != 0)
		{
			*tmp1 = '\0';
			if (!(*line = ft_strnew(ft_strlen(cur->content))))
			{
				if (head)
					ft_lstdel(&head, del);
				return (-1);
			}
			ft_strcpy(*line, cur->content);
			tmp1++;
			if (!(cur->content = ft_strdup(tmp1)))
			{
				if (head)
					ft_lstdel(&head, del);
				return (-1);
			}
			return (1);
		}
		else
		{
			if (!(cur->content = ft_strnew2(cur->content, BUFF_SIZE)))
			{
				if (head)
					ft_lstdel(&head, del);
				return (-1);
			}
			tmp = cur->content;
			tmp += ft_strlen(cur->content);
		}
	}
	if (ft_strlen(cur->content) != 0)
	{
		if ((tmp1 = ft_strchr(tmp, '\n')) != 0)
		{
			*tmp1 = '\0';
			if (!(*line = ft_strnew(ft_strlen(cur->content))))
			{
				if (head)
					ft_lstdel(&head, del);
				return (-1);
			}
			ft_strcpy(*line, cur->content);
			tmp1++;
			if (!(cur->content = ft_strdup(tmp1)))
			{
				if (head)
					ft_lstdel(&head, del);
				return (-1);
			}
			return (1);
		}
		else
		{
			if (!(*line = ft_strnew(ft_strlen(cur->content))))
			{
				if (head)
					ft_lstdel(&head, del);
				return (-1);
			}
			ft_strcpy(*line, cur->content);
			free(cur->content);
			cur->content = 0;
		}
	}
	return (0);
}
