/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 16:40:47 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/15 15:05:51 by hkalia           ###   ########.fr       */
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
	char	*str;

	fd = open("file", O_RDONLY);
	if (get_next_line(fd, &str) == -1)
		printf("error\n");
	else
	{
		printf("%s\n", str);
		free(str);
/*		get_next_line(fd, &str);
		printf("%s\n", str);*/
	}
	close(fd);
	return (0);
}
