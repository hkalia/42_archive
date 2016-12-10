/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:24:01 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/10 15:26:36 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NBR_H
# define NBR_H

#include <stdint.h>

short	ft_nbrlen_base(uintmax_t src, short base);
short	ft_nbrlen(intmax_t src);
void	ft_putnbr_base(long long src, int base);
void	ft_putnbr_fd(int src, int fd);
void	ft_putnbr(int src);

#endif
