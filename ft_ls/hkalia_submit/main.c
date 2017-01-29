/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:28:07 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/28 14:02:53 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

uint8_t			g_ft_ls_flgs = 0;
int8_t			ret = 0;

static int8_t	parser(int argc, char **argv)
{
	int		i;
	size_t	j;

	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		if (argv[i][1] == '-')
			break ;
		j = 0;
		while (argv[i][++j] != 0)
		{
			if (argv[i][j] == 'l')
				g_ft_ls_flgs |= 0x1;
			else if (argv[i][j] == 'R')
				g_ft_ls_flgs |= 0x2;
			else if (argv[i][j] == 'a')
				g_ft_ls_flgs |= 0x4;
			else if (argv[i][j] == 'r')
				g_ft_ls_flgs |= 0x8;
			else if (argv[i][j] == 't')
				g_ft_ls_flgs |= 0x10;
			else if (argv[i][j] == '1');
			else
				return (-1);
		}
		++i;
	}
	if (i < argc)
		GRD1(ft_ls_handle_args(i, argc, argv) == -1, ret = -1);
	else
		ft_ls_print_dir(".");
	return (ret);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_ls_print_dir(".");
	else if (argc > 1)
		GRD1(parser(argc, argv) == -1, return (-1));
	else
		return(-1);
	return (ret);
}
