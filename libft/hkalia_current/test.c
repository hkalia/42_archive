/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:52:57 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/13 14:15:19 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <libft.h>
#include <stdio.h>

int		main(void)
{
	char *test;

	test = ft_calloc(5, 1);
	ft_strcpy(test, "test");
	test = ft_reallocf(test, 4, 10);
	ft_strcpy(&test[4], "test");
	printf("%s\n", test);
	return 0;
}
