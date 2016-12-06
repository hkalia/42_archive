/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_reserve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:17:14 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/06 12:21:49 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>

#define utarray_reserve(a,by) do {                                            \
  if (((a)->i+(by)) > (a)->n) {                                               \
    char *utarray_tmp;                                                        \
    while (((a)->i+(by)) > (a)->n) { (a)->n = ((a)->n ? (2*(a)->n) : 8); }    \
    utarray_tmp=(char*)realloc((a)->d, (a)->n*(a)->icd.sz);                   \
    if (utarray_tmp == NULL) oom();                                           \
    (a)->d=utarray_tmp;                                                       \
  }                                                                           \
} while(0)

int8_t	arr_reserve(t_arr *src, size_t sze)
{
	char	*tmp;

	if (src->len + sze > src->cap)
	{
		while (src->len + sze > src->cap)
			src->len = src->len ? 2 * src->len : 8;
	    utarray_tmp=(char*)realloc(src->d, src->n*src->icd.sz);                   \
	    if (utarray_tmp == NULL) oom();                                           \
	    (a)->d=utarray_tmp;                                                       \
	}
	return (0);
}
