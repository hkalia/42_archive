#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static char		**ft_tbldel2(char **tbl)
{
	size_t	i;

	i = 0;
	while (tbl[i])
	{
		free(tbl[i]);
		i++;
	}
	free(tbl);
	return (NULL);
}

static size_t	ft_nbr_wrd_in_str(const char *src, char src_x)
{
	size_t	nbr_wrd;
	int		flwrd;

	nbr_wrd = 0;
	flwrd = 0;
	while (*src)
	{
		if (*src == src_x && flwrd == 1)
			flwrd = 0;
		if (*src != src_x && flwrd == 0)
		{
			flwrd = 1;
			nbr_wrd++;
		}
		src++;
	}
	return (nbr_wrd);
}

static char		*ft_wrddup(const char *src, char src_x)
{
	char	*wrd;
	size_t	wrd_len;
	size_t	i;

	wrd_len = 0;
	i = 0;
	while (src[wrd_len] && src[wrd_len] != src_x)
		wrd_len++;
	if (!(wrd = (char *)malloc(sizeof(char) * (wrd_len + 1))))
		return (NULL);
	while (i < wrd_len)
	{
		wrd[i] = src[i];
		i++;
	}
	wrd[i] = '\0';
	return (wrd);
}

char			**ft_strsplit(const char *src, char src_x)
{
	char	**table;
	size_t	nbr_wrd;
	size_t	i;
	int		flwrd;

	i = 0;
	flwrd = 0;
	nbr_wrd = ft_nbr_wrd_in_str(src, src_x);
	if (!(table = (char **)malloc(sizeof(char *) * (nbr_wrd + 1))))
		return (NULL);
	table[nbr_wrd] = NULL;
	while (*src && i < nbr_wrd)
	{
		if (*src == src_x && flwrd == 1)
			flwrd = 0;
		if (*src != src_x && flwrd == 0)
		{
			flwrd = 1;
			if (!(table[i] = ft_wrddup(src, src_x)))
				return (ft_tbldel2(table));
			i++;
		}
		src++;
	}
	return (table);
}

void	ft_putendl(const char *src)
{
	while (*src)
	{
		write(1, src, 1);
		src++;
	}
	write(1, "\n", 1);
}

void	ft_puttbl(char **tbl)
{
	size_t	i;

	i = 0;
	while (tbl[i])
	{
		ft_putendl(tbl[i]);
		i++;
	}
}

void	ft_tbldel(char ***tbl)
{
	size_t	i;

	i = 0;
	while (*tbl[i])
	{
		write(1, "o\n", 2);
		ft_putendl(*tbl[i]);
		free(*tbl[i]);
		write(1, "l\n", 2);
		i++;
		write(1, "p\n", 2);
	}
	free(*tbl[i]);
	free(**tbl);
	**tbl = 0;
}

int		main(void)
{
	char	str[] = "hello my name is habib";
	char	**tbl;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tbl = ft_strsplit(str, ' ');
	ft_puttbl(tbl);
	ft_tbldel(&tbl);
	if (tbl == 0)
		ft_putendl("hello");
	return (0);
}
