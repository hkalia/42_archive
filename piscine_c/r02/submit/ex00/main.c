/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 21:38:48 by hkalia            #+#    #+#             */
/*   Updated: 2016/07/31 21:38:51 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_2.h"

void	call_rush(char *str)
{
	int		x;
	int		y;
	int		call;

	call = 0;
	x = find_x(str);
	y = find_y(str);
	if ((ft_strcmp(str, convert(rush00(x, y)))) == 0)
		print_res(0, x, y, call++);
	if ((ft_strcmp(str, convert(rush01(x, y)))) == 0)
		print_res(1, x, y, call++);
	if ((ft_strcmp(str, convert(rush02(x, y)))) == 0)
		print_res(2, x, y, call++);
	if ((ft_strcmp(str, convert(rush03(x, y)))) == 0)
		print_res(3, x, y, call++);
	if ((ft_strcmp(str, convert(rush04(x, y)))) == 0)
		print_res(4, x, y, call++);
	if (call == 0)
		ft_putstr("aucune");
	ft_putchar('\n');
}

int		main(void)
{
	t_node	*head;
	char	buf;
	char	*str;

	head = NULL;
	while (read(0, &buf, 1))
		add_node_end(&head, buf);
	str = (char*)malloc(sizeof(char) * ft_list_size(head) + 1);
	assign(str, head);
	clear_list(&head);
	call_rush(str);
	return (0);
}
