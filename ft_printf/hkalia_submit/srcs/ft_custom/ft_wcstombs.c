/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcstombs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:27:08 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/13 15:21:19 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_custom.h>
#include <ft_stdlib.h>

int		ft_wcstombs(char **dst, const wint_t *src)
{
	size_t	i;
	size_t	j;

	if (dst == 0 || src == 0 || src[0] == 0)
		return (-1);
	i = 0;
	while (src[i])
		++i;
	if (!(*dst = ft_calloc((i * sizeof(wint_t)) + 1, sizeof(char))))
		return (-1);
	i = 0;
	j = 0;
	while(src[i])
	{
		j += ft_wctomb(&((*dst)[j]), src[i]);
		++i;
	}
	return (j);
}
