void	sort_int_tab(int *tab, unsigned int size)
{
	int				*tmp;
	int				tmp1;
	unsigned int	i;
	int				flag;

	if (!(size > 1))
		return ;
	while (1)
	{
		i = 0;
		flag = 0;
		while (i < size - 1)
		{
			tmp = &tab[i + 1];
			if (tab[i] > *tmp)
			{
				tmp1 = tab[i];
				tab[i] = *tmp;
				*tmp = tmp1;
				flag = 1;
			}
			i++;
		}
		if (flag == 0)
			return ;
	}
}
