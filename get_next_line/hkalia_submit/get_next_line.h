/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 15:22:05 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/15 15:47:23 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1
# define STRDEL_RETURN(a, b) {ft_strdel(&a); return (b);}
# define STRDEL_STRDEL_RETURN(a, b, c) {ft_strdel(&a); ft_strdel(&b); return (c);}

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct			s_info
{
	int					*fd_arr;
	unsigned long long	fd_arr_size;
	char				**tbl;
}						t_info;

int 	get_next_line(const int fd, char **line);

#endif
