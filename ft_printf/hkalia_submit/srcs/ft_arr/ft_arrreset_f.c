/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrreset_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:21:21 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/21 09:58:25 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_arr.h>
#include <stdlib.h>

void	ft_arrreset_f(t_arr *src)
{
	if (src)
	{
		src->arr_sze = 0;
		src->arr_len = 0;
		free(src->arr);
		src->arr = 0;
	}
}
