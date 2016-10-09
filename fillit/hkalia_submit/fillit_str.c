/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 14:40:05 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/08 16:38:37 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putstr(const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		write(1, &src[i], 1);
		i++;
	}
}

void	ft_putendl(const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		write(1, &src[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strnew(int len)
{
	int		i;
	char	*new;

	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		new[i] = '\0';
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	ft_strdel(char **src)
{
	free(*src);
	*src = NULL;
}
