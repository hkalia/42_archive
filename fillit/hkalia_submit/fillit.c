#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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

/*
char	*tet[]=	{"####", "#...#...#...#",
				"#...###", "##..#...#", "###...#", "#...#..##",
				"#.###", "#...#...##", "###.#", "##...#...#",
				"##..##",
				"##.##", "#...##...#",
				"#..###", "#...##..#", "###..#", "#..##...#",
				"##...##", "#..##..#"};*/

void	ft_putstr(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		write(1, &src[i], 1);
		i++;
	}
}

char	*ft_strnew(size_t len)
{
	size_t	i;
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

char	**ft_tblnew(size_t len)
{
	size_t	i;
	char	**new;

	if (!(new = (char **)malloc(sizeof(char *) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		new[i] = 0;
		i++;
	}
	new[i] = 0;
	return (new);
}

void	ft_strdel(char **src)
{
	free(*src);
	*src = NULL;
}

void	ft_tbldel(char ***tbl)
{
	size_t	i;

	i = 0;
	while (*tbl[i])
	{
		free(*tbl[i]);
		i++;
	}
	free(**tbl);
	*tbl = 0;
}
/*
char	*solve(char *src)
{
	if (1)
		return ("under construction\n");
	else
		return (NULL);
}
*/
int		validate2(char *src, int *blck_cnt)
{
	int		i;
	int		dot_cnt;
	int		line_cnt;

	i = 0;
	dot_cnt = 0;
	line_cnt = 0;
	while (src[i])
	{
		if (src[i] == '.' || src[i] == '#')
			dot_cnt++;	
		if (src[i] == '\n' && (src[i + 1] != '\n' && src[i + 1] != '\0'))
		{
			if (dot_cnt != 4)
				return (1);
			else
				dot_cnt = 0;
		}
		if (src[i] == '\n' && (src[i - 1] == '.' || src[i - 1] == '#'))
			line_cnt++;
		if (src[i] == '\n' && (src[i + 1] == '\n' || src[i + 1] == '\0'))
		{
			if (line_cnt != 4)
				return (1);
			else
			{
				line_cnt = 0;
				(*blck_cnt)++;
			}
		}
		i++;
	}
	return (0);
}

void	validate1(char *src, int *src_len, int *line_cnt)
{
	int		i;

	i = 0;
	while (*src)
	{
		if (*src != '.' && *src != '#' && *src != '\n')
		{
			*src_len = 1;
			return ;
		}
		if (*src == '\n')
			(*line_cnt)++;
		src++;
		(*src_len)++;
	}
}

int		validation_caller(char	*src)
{
	int		src_len;
	int		line_cnt;
	int		blck_cnt;
//	char	**src_tbl;

	src_len = 0;
	line_cnt = 0;
	blck_cnt = 0;
	validate1(src, &src_len, &line_cnt);
	if (src_len < 21 || line_cnt > 129)
		return (1);
	if (validate2(src, &blck_cnt))
		return (1);
	printf("%d\n", blck_cnt);
	/*if (!(src_tbl = ft_tblnew(blck_nbr)))
		return (1);
	if (assign_tbl(src_tbl))
	{
		ft_tbldel(src_tbl);
		return (1);
	}*/
	return (0);
}

int		main_caller(char *file)
{
	int		fd;
	char	*src;

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
	if (validation_caller(src))
	{
		ft_strdel(&src);
		return (1);
	}
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
