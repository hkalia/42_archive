/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 21:38:14 by hkalia            #+#    #+#             */
/*   Updated: 2016/07/30 21:38:16 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_2.h"

t_node	*create_new_node(char c)
{
	t_node	*new_node;

	new_node = (t_node*)malloc(sizeof(t_node));
	new_node->data = c;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_end(t_node **head, char c)
{
	t_node *tmp;

	tmp = *head;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_new_node(c);
	}
	else
		*head = create_new_node(c);
}

int		ft_list_size(t_node *head)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	assign(char *str, t_node *head)
{
	t_node	*tmp;
	int		i;

	tmp = head;
	i = 0;
	while (tmp)
	{
		str[i] = tmp->data;
		i++;
		tmp = tmp->next;
	}
	str[i] = '\0';
}

void	clear_list(t_node **head)
{
	t_node *tmp;

	if (*head)
	{
		while ((*head)->next)
		{
			tmp = *head;
			*head = (*head)->next;
			free(tmp);
		}
	}
	*head = NULL;
}
