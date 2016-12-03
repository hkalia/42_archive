/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 16:40:59 by hkalia            #+#    #+#             */
/*   Updated: 2016/10/25 16:41:04 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 20
# define STR_GUARD(a) {ft_strdel(a); return (-1);}
# define LST_GUARD(a) if (a) {ft_lstdel(&head, del); return (-1);}
# define IF_LST_GUARD(a) if (a) {if (head) ft_lstdel(&head, del); return (-1);}

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int		get_next_line(const int fd, char **line);

#endif
