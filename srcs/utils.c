/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:29:37 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/30 14:14:20 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_news(char c)
{
	return (c == 'N' || c == 'E' || c == 'W' || c == 'S' || c == '0'
		|| c == '1');
}

int	valid_character(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == '0' || c == 'E' || c == '1'
		|| c == ' ');
}

int	is_character(char c)
{
	return (c == 'N' || c == 'E' || c == 'W' || c == 'S');
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

void	fill_space_one(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (ft_isspace(map[i][j]) || is_news(map[i][j]))
		{
			if (ft_isspace(map[i][j]))
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}
