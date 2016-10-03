/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:37:27 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/29 15:52:23 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*i;

	new = f(lst);
	i = new;
	while (lst->next)
	{
		i->next = f(lst->next);
		i = i->next;
		lst = lst->next;
	}
	return (new);
}
