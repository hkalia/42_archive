/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:40:11 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 12:27:45 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <str.h>
#include <stdlib.h>

char	*ft_strnew(size_t len)
{
	char	*new;

	GRD((new = malloc(sizeof(char) * (len + 1))) == 0, 0);
	while (len)
	{
		new[len] = 0;
		--len;
	}
	new[len] = 0;
	return (new);
}
