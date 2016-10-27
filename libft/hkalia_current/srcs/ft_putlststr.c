/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlststr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:15:45 by hkalia            #+#    #+#             */
/*   Updated: 2016/09/29 15:16:50 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_custom.h>
#include "libft.h"

void	ft_putlststr(t_list *elem)
{
	char	*str;

	str = elem->content;
	ft_putendl(str);
}
