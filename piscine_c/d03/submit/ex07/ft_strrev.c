/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 21:13:47 by hkalia            #+#    #+#             */
/*   Updated: 2016/07/14 21:14:09 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		begin;
	int		end;
	char	tmp;

	end = 0;
	begin = 0;
	
	while (str[end] != '\0')
	{
		end++;
	}
	
	end--;

	while (begin < end)
	{
		tmp = str[end];
		str[end] = str[begin];
		str[begin] = tmp;
		begin++;
		end--;
	}
	
	return (str);
} 
