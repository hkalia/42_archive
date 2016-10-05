int		ft_atoi(const char *str)
{
	int		flg_neg;
	long	nbr;

	while (*str == ' ' || *str == '\f' || *str == '\t'
			|| *str == '\n' || *str == '\r' || *str == '\v')
	   str++;
	flg_neg = (*str == '-' ? -1 : 1);
	str = ((*str == '-' || *str == '+') ? str + 1 : str);
	while (*str == '0')
		str++;
	nbr = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * flg_neg);
}
