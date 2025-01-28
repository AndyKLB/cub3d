/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rsubstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:32:35 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/28 12:43:59 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rsubstr(char const *s, unsigned int end, size_t len)
{
	char	*new;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	if (end > s_len)
		end = s_len;
	if (len > end)
		len = end;
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
