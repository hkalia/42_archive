/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 16:40:47 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/14 16:41:25 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(void)
{
	int		fd;
	char	*str;

	fd = open(file, O_RDONLY);
	str = ft_strnew(500);
	get_next_line(fd, &str);
	ft_putstr(str);
	return (0);
}
