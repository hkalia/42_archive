/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:36:25 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/31 18:49:36 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

#define PRINTF_SPEC_1 "%-+ #0123456789*."
#define PRINTF_LEN_SPEC {"hh", "h", "l", "ll", "j", "z"}
#define PRINTF_CONV_SPEC "CcDdiOopSsUuXx"
#define PRINTF_FUNC_LIST int (*func_arr[14])(t_printf_store *, va_list *) =\
							{printf_C, printf_c}

typedef struct	s_printf_store
{
	bool	flag_minus;
	bool	flag_plus;
	bool	flag_space;
	bool	flag_hash;
	bool	flag_zero;
	int		flag_min_field_width;
	int		flag_precision;
	int		flag_len_mod;
}				t_printf_store;

int		printf_C(t_printf_store *storage, va_list *ap)
{
	(void)ap;
	(void)storage;
	return(write(1, "C", 1));
}

int		printf_c(t_printf_store *storage, va_list *ap)
{
	(void)ap;
	(void)storage;
	return(write(1, "c", 1));
}

int		modparse(const char **fmt, va_list *ap, t_printf_store *storage)
{
	if (**fmt == '%')
	{
		++(*fmt);
		write(1, "%", 1);
		return (1);
	}
	(void)ap;
	(void)storage;
	return (0);
}

int		dispatcher(const char **fmt, va_list *ap)
{
	char			*spec;
	t_printf_store	storage;
	int				i;
	int				ret;

	spec = PRINTF_CONV_SPEC;
	PRINTF_FUNC_LIST;
	storage = (t_printf_store){0,0,0,0,0,0,0,0};
	if (*(*fmt + 1) == 0)
		return (-1);
	++(*fmt);
	if ((ret = modparse(&(*fmt), &(*ap), &storage)))
		return (ret);
	i = 0;
	while (spec[i])
	{
		if (spec[i] == **fmt)
		{
			ret = (*func_arr[i])(&storage, &(*ap));
			++(*fmt);
			return (ret);
		}
		++i;
	}
	return (-1);
}

void	iterator(const char *fmt, int *ret, va_list *ap)
{
	int		i;
	int		j;

	while (*fmt)
	{
		i = 0;
		if (*fmt == '%')
		{
			j = 0;
			if ((*ret += dispatcher(&fmt, &(*ap))) < 0)
				return ;
		}
		else if (ft_strchr(fmt, '%') == 0)
		{
			*ret += write(1, fmt, ft_strlen(fmt));
			return ;
		}
		else
		{
			while (fmt[i] != '%')
				++i;
			*ret += write(1, fmt, i);
			fmt += i;
		}
	}
}

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		ret;

	ret = 0;
	if (fmt == 0 || *fmt == 0)
		return (0);
	if (ft_strchr(fmt, '%') == 0)
		return (write(1, fmt, ft_strlen(fmt)));
	else
	{
		va_start(ap, fmt);
		iterator(fmt, &ret, &ap);
		va_end(ap);
	}
	return (ret);
}
