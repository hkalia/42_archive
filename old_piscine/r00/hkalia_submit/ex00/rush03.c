/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 20:19:46 by hkalia            #+#    #+#             */
/*   Updated: 2016/07/16 20:19:49 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_printline(int x, char fst, char mid, char lst)
{
	ft_putchar(fst);
	x--;
	while (x > 1)
	{
		ft_putchar(mid);
		x--;
	}
	if (x == 1)
	{
		ft_putchar(lst);
	}
	ft_putchar(10);
}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		ft_printline(x, 'A', 'B', 'C');
		y--;
		while (y > 1)
		{
			ft_printline(x, 'B', ' ', 'B');
			y--;
		}
		if (y == 1)
			ft_printline(x, 'A', 'B', 'C');
	}
}
