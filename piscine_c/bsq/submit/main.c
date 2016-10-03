/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfriedri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 14:42:00 by mfriedri          #+#    #+#             */
/*   Updated: 2016/08/03 18:00:42 by mfriedri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		put_map_error(void)
{
	ft_putstr("map error\n");
	return (-1);
}

int		test_input(int argc, char **argv)
{
	int		i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			if ((create_str(argv[i])) == -1)
				return (-1);
			i++;
		}
	}
	else if (ft_stdin() == 1)
	{
		if ((create_str("stdin_map")) == -1)
			return (-1);
	}
	else
		return (-1);
	return (0);
}

int		main(int argc, char **argv)
{
	if (test_input(argc, argv) == -1)
		put_map_error();
	else if (g_empty_sq == '\0' || g_blocked_sq == '\0' || g_fill_sq == '\0')
		put_map_error();
	else
		return (0);
}
