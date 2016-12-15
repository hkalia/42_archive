/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tbl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:08:00 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/12 11:12:27 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TBL_H
# define TBL_H

# include <stddef.h>

void	ft_puttbl(char **tbl);
void	ft_tbldel(char **tbl);
char	**ft_tblnew_2(int len, int str_len);
char	**ft_tblnew(int len);

#endif
