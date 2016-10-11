/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 15:25:03 by dmclaugh          #+#    #+#             */
/*   Updated: 2016/10/10 19:57:24 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* 
** 0	"####"			I
** 1	"#...#...#...#"	I
** 2	"#...###"		J
** 3	"##..#...#"		J
** 4	"###...#"		J
** 5	"#...#..##"		J
** 6	"#.###"			L
** 7	"#...#...##"	L
** 8	"###.#"			L
** 9	"##...#...#"	L
** 10	"##..##"		O
** 11	"##.##"			S
** 12	"#...##...#"	S
** 13	"#..###"		T
** 14	"#...##..#"		T
** 15	"###..#"		T
** 16	"#..##...#"		T
** 17	"##...##"		Z
** 18	"#..##..#"		Z
*/
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

int		main_caller(char *file)
{
	int		fd;
	char	*src;
	int		*tetri;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (1);
	if (!(src = ft_strnew(545)))
	{
		close(fd);
		return (1);
	}
	if (read(fd, src, 545) == -1)
	{
		close(fd);
		ft_strdel(&src);
		return (1);
	}
	if (read(fd, src, 1) != 0)
	{
		close(fd);
		ft_strdel(&src);
		return (1);
	}
	close(fd);
	if (!(tetri = validation_caller(src)))
	{
		ft_strdel(&src);
		return (1);
	}
	ft_putnbrstr(tetri);
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(1);
		return (1);
	}
	if (main_caller(argv[1]))
	{
		ft_putstr("error\n");
		exit(1);
		return(1);
	}
	exit(0);
	return(0);
}
