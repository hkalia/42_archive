/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:21:21 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/18 15:45:13 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_arr.h>
#include <stdlib.h>

void	ft_arrdel(t_arr **src)
{
	if (src)
	{
		if (*src)
		{
			free((*src)->arr);
			free(*src);
			*src = 0;
		}
	}
}
