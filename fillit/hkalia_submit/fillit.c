#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define	TET1	"110011"		//square
#define	TET2	"####"			//horizontal I
#define	TET3	"#...#...#...#"	//vertical I
#define TET4	"##.##"			//horizontal S
#define TET5	"#...##...#"	//vertical S
#define TET6	"##...##"		//horizontal Z
#define	TET7	".#..##..#"		//vertical Z
#define	TET8	"###..#"		//0 T
#define	TET9	"#..##...#"		//90 T
#define	TET10	"#..###"		//180 T
#define	TET11	"#...##..#"		//270T
#define	TET12	"#...#..##"		//0 J
#define	TET13	"#...###"		//90 J
#define	TET14	"##..#...#"		//180 J
#define TET15	"###...#"		//270 J
#define	TET16	"#...#...##"	//0 L
#define	TET17	"###.#"			//90 L
#define	TET18	"##...#...#"	//180 L
#define	TET19	"#.###"			//270 L

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
	char	*new;
	char	*new_cpy;

	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	new_cpy = new;
	while (len--)
		*new_cpy++ = '\0';
	*new_cpy = '\0';
	return (new);
}

void	ft_strdel(char **src)
{
	free(*src);
	*src = NULL;
}

char	*solve(char *src)
{
	if (1)
		return ("under construction\n");
	else
		return (NULL);
}

int		validation_caller(char	*src)
{
	ft_putstr(src);
	return (0);
}

int		main_caller(char *file)
{
	int		fd;
	char	*buffer;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (1);
	if (!(buffer = ft_strnew(545)))
	{
		close(fd);
		return (1);
	}
	if (read(fd, buffer, 545) == -1)
	{
		close(fd);
		ft_strdel(&buffer);
		return (1);
	}
	if (read(fd, buffer, 1) != 0)
	{
		close(fd);
		ft_strdel(&buffer);
		return (1);
	}
	if (validation_caller(buffer))
	{
		close(fd);
		ft_strdel(&buffer);
		return (1);
	}
	close(fd);
	ft_strdel(&buffer);
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
