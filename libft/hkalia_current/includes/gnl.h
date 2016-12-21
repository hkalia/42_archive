/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 16:40:59 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/21 10:51:09 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# ifndef GRDS
#  define GRD(a, b) do{if(a){return(b);}}while(0)
#  define GRD1(a, b, c) do{if(a){b;return(c);}}while(0)
#  define GRD2(a, b, c, d) do{if(a){b;c;return(d);}}while(0)
#  define GRD3(a, b, c, d, e) do{if(a){b;c;d;return(e);}}while(0)
# endif

# define GNL_BUFF_SIZE 20
# define GNL_MAX_FD 4864

# include <arr.h>
# include <ft_stdlib.h>
# include <ft_string.h>
# include <stdlib.h>
# include <unistd.h>

int		gnl(const int fd, char **line);

#endif
