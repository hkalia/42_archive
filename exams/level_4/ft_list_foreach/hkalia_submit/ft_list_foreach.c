#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*cpy;

	cpy = begin_list;
	while (cpy)
	{
		(*f)(cpy->data);
		cpy = cpy->next;
	}
}
