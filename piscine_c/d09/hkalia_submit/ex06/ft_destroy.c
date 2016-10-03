/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 11:19:19 by hkalia            #+#    #+#             */
/*   Updated: 2016/07/22 11:19:22 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ultimator.h"

void	ft_destroy(char ***factory)
{
	int	i;
	int	j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (factory[i])
	{
		while (factory[i][j])
		{
			while (factory[i][j][k])
			{
				free(factory[i][j][k]);
				k++;
			}
			j++;
		}
		i++;
	}
}
