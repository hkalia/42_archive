/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:02:27 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/20 15:44:43 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fcntl.h>

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;
//
// 	if (argc > 1)
// 		GRD((fd = open(argv[1], O_RDONLY)) == -1, -1);
// 	else
// 		fd = 0;
// 	while (gnl(fd, &line))
// 	{
// 		ft_printf("%s\n", line);
// 		free(line);
// 	}
// 	if (fd != 0)
// 		close(fd);
// 	return (0);
// }

int	main(void)
{
	char	*line;

	gnl(2, &line);
	return (0);
}
