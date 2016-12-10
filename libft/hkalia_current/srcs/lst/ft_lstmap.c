/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:37:27 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/10 15:44:59 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lst.h>

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
