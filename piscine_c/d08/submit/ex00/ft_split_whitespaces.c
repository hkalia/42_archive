/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 11:45:24 by hkalia            #+#    #+#             */
/*   Updated: 2016/07/21 11:45:26 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_nb_words(char *str)
{
	int	nb_words;
	int	i;
	int flwrd;

	i = 0;
	nb_words = 0;
	flwrd = 0;
	while (str[i])
	{
		if ((str[i] == '\n' || str[i] == ' ' || str[i] == '\t') && flwrd == 1)
			flwrd = 0;
		if ((str[i] != '\n' && str[i] != ' ' && str[i] != '\t') && flwrd == 0)
		{
			flwrd = 1;
			nb_words++;
		}
		i++;
	}
	return (nb_words);
}

int		get_word_location(int k, char *str)
{
	while (str[k])
	{
		if (str[k] != '\n' && str[k] != ' ' && str[k] != '\t')
			break ;
		k++;
	}
	return (k);
}

int		get_word_size(int k, char *str)
{
	int start;

	start = k;
	while (str[k] != '\0' && str[k] != '\n' && str[k] != ' ' && str[k] != '\t')
		k++;
	return (k - start);
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	int		k;
	int		word_size;
	char	**chstr;

	i = 0;
	k = 0;
	chstr = (char**)malloc(sizeof(char*) * (get_nb_words(str) + 1));
	while (i < get_nb_words(str))
	{
		j = 0;
		k = get_word_location(k, str);
		word_size = get_word_size(k, str);
		chstr[i] = (char*)malloc(sizeof(char) * (word_size + 1));
		while (j < word_size)
			chstr[i][j++] = str[k++];
		chstr[i][j] = '\0';
		i++;
	}
	chstr[get_nb_words(str)] = 0;
	return (chstr);
}
