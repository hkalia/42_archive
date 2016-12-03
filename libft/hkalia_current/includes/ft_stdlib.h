/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 13:09:37 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/03 08:44:30 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stddef.h>

int		ft_abs(int src);
int		ft_atoi(const char *src);
void	*ft_calloc(size_t count, size_t size);
int		ft_wctomb(char *s, wchar_t wchar);

#endif
