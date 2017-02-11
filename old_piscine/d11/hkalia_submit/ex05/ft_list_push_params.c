/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 20:35:30 by hkalia            #+#    #+#             */
/*   Updated: 2016/07/26 20:35:33 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list *list;
	t_list *begin_list;

	list = 0;
	begin_list = 0;
	if (ac > 0)
	{
		begin_list = ft_create_elem((void*)*(av + (ac - 1)));
		list = begin_list;
		ac--;
		while (ac > 0)
		{
			list->next = ft_create_elem((void*)*(av + (ac - 1)));
			list = list->next;
			ac--;
		}
	}
	return (begin_list);
}
