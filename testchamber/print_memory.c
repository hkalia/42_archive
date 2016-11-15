/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:13:10 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/15 07:22:12 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_chars(const unsigned char *addr, size_t size, size_t i)
{
	int		j;

	j = 0;
	while (j < 16 && i + j < size)
	{
		if (*(addr + i + j) >= ' ' && *(addr + i + j) <= '~')
			write(1, (addr + i + j), 1);
		else
			write(1, ".", 1);
		++j;
	}
}

static void	ft_putnbr_hex(int octet, int rem)
{
	char	*spec = "0123456789abcdef";

	if (rem > 1)
		ft_putnbr_hex(octet >> 4, rem - 1);
	write(1, spec + (octet % 16), 1);
}

static void	print_addr(const unsigned char *addr, size_t size, size_t i)
{
	int		j;

	j = 0;
	while (j < 16 && j + i < size)
	{
		ft_putnbr_hex(*(addr + i + j), 2);
		if (j % 2)
			write(1, " ", 1);
		++j;
	}
	while (j < 16)
	{
		write(1, "  ", 2);
		if (j % 2)
			write(1, " ", 1);
		++j;
	}
}

void	print_memory(const void *addr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		print_addr((const unsigned char *)addr, size, i);
		print_chars((const unsigned char *)addr, size, i);
		write(1, "\n", 1);
		i += 16;
	}
}

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255, 12, 16, 21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}
