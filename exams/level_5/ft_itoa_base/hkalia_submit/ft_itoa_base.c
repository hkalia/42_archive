#include <stdlib.h>

int		ft_nbrlen_base(int value, int base)
{
	int		ret;

	ret = 0;
	if (value == 0)
		return (1);
	if (value < 0 && base == 10)
		++ret;
	while (value != 0)
	{
		value = value / base;
		++ret;
	}
	return (ret);
}

char	*ft_itoa_base(int value, int base)
{
	long	value_cpy;
	int		value_len;
	int		flg_neg;
	char	*spec = "0123456789ABCDEF";
	char	*ret;

	if (base < 2)
		return (0);
	value_len = ft_nbrlen_base(value, base);
	ret = (char *)malloc(sizeof(char) * (value_len + 1));
	ret[value_len] = 0;
	value_cpy = value;
	flg_neg = value_cpy < 0 && base == 10 ? 1 : 0;
	value_cpy = value_cpy < 0 ? -value_cpy : value_cpy;
	while (--value_len)
	{
		ret[value_len] = spec[value_cpy % base];
		value_cpy = value_cpy / base;
	}
	ret[value_len] = flg_neg ? '-' : spec[value_cpy % base];
	return (ret);
}
