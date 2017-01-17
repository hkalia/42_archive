/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:02:27 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/15 13:16:11 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc > 1)
		GRD((fd = open(argv[1], O_RDONLY)) == -1, -1);
	else
		fd = 0;
	while (gnl(fd, &line) == 1)
	{
		printf("|%s|\n", line);
		free(line);
	}
	if (fd != 0)
		close(fd);
	return (0);
}
