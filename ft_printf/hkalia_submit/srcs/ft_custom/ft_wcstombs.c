/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcstombs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:27:08 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/23 11:05:10 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_custom.h>
#include <ft_stdlib.h>
#include <stdlib.h>

int		ft_wcstombs(char **dst, const wint_t *src)
{
	size_t	i;
	size_t	j;
	int		tmp;

	if (!src || !dst)
		return (-1);
	*dst = 0;
	i = 0;
	while (src[i])
		++i;
	FT_GRD(!(*dst = ft_calloc(i + 1, sizeof(wint_t))), -1);
	i = 0;
	j = 0;
	while (src[i])
	{
		FT_GRD2((tmp = ft_wctomb(&((*dst)[j]), src[i])) == -1, free(*dst)
				, *dst = 0, -1);
		j += tmp;
		++i;
	}
	return (j);
}
