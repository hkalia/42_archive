/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcstombs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:27:08 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/17 17:01:36 by hkalia           ###   ########.fr       */
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

	i = 0;
	if (src)
		while (src[i])
			++i;
	if (!(*dst = ft_calloc(i + 1, sizeof(wint_t))))
		return (-1);
	if (i == 0)
		return (0);
	i = 0;
	j = 0;
	while (src && src[i])
	{
		if ((tmp = ft_wctomb(&((*dst)[j]), src[i])) == -1)
		{
			free(*dst);
			return (-1);
		}
		j += tmp;
		++i;
	}
	return (j);
}
