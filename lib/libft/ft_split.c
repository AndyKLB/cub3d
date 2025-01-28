/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:59:56 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/28 12:18:44 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	fill_tab(char *s_new, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		s_new[i] = s[i];
		i++;
	}
	s_new[i] = '\0';
}

void	free_tab(int k, char ***tab)
{
	if (k == 0)
		return ;
	while (k > 0)
	{
		free((*tab)[k]);
		(*tab)[k] = NULL;
		k--;
	}
}

static int	set_alloc(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j > 0)
		{
			tab[k] = malloc(sizeof(char) * (j + 1));
			if (!tab[k])
				return (free_tab(k, &tab), 1);
			fill_tab(tab[k], s + i, c);
			k++;
			i += j;
		}
		else
			i++;
	}
	tab[k] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	if (set_alloc(tab, s, c))
	{
		free(tab);
		tab = NULL;
	}
	return (tab);
}
