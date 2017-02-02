/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:37:30 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 12:00:44 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lst.h>
#include <ft_string.h>
#include <stdlib.h>

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*new;

	GRD((new = (t_list*)malloc(sizeof(t_list))) == 0, 0);
	if (content == 0)
	{
		new->content = 0;
		new->content_size = 0;
	}
	else
	{
		GRD((new->content = malloc(content_size)) == 0, 0);
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = 0;
	return (new);
}
