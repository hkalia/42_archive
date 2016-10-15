/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 16:40:47 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/15 16:48:40 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/uio.h>
#include <sys/types.h>

int		main(void)
{
	int		fd;
	int		ret;
	char	*str;

	fd = open("file", O_RDONLY);
	while ((ret = get_next_line(fd, &str)))
	{
		printf("%d %s\n", ret, str);
		free(str);
	}
	printf("%d %s\n", ret, str);
	free(str);
	close(fd);
	return (0);
}
