/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:40:01 by hkalia            #+#    #+#             */
/*   Updated: 2016/11/11 17:14:09 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_custom.h>
#include <ft_string.h>
#include <ft_stdlib.h>
#include <stdlib.h>

int		ft_printf_mod(char **ret, const char **fmt,
						va_list *ap, t_printf_parse *parse_state)
{
	char	*new;

	(void)ap;
	PRINTF_STR_GRD(!(new = ft_calloc(2, sizeof(char))), ret, -1);
	new[0] = '%';
	PRINTF_STR_GRD(!(*ret = ft_strextend(*ret, 1)), &new, -1);
	ft_strcat(*ret, new);
	PRINTF_STR_GRD(width_handler(ret, parse_state, new) == -1, &new, -1);
	free(new);
	++*fmt;
	return (1);
}
