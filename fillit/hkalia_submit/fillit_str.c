/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 14:40:05 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/12 08:52:26 by hkalia           ###   ########.fr       */
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

int		ft_strequ(const char *src1, const char *src2)
{
	while (*src1 == *src2)
	{
		if (*src1 == '\0')
			return (1);
		src1++;
		src2++;
	}
	return (0);
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

void	ft_putchar(char src)
{
	write(1, &src, 1);
}

void	ft_putnbr(int src)
{
	int		src_cpy;

	src_cpy = src;
	if (src_cpy > 9)
	{
		ft_putnbr(src_cpy / 10);
		ft_putnbr(src_cpy % 10);
	}
	else
		ft_putchar(src_cpy + '0');
}

void	ft_putnbrstr(int *src)
{
	int		i;

	i = 0;
	while (src[i] != 42)
	{
		ft_putnbr(src[i]);
		ft_putchar('\n');
		i++;
	}
}
