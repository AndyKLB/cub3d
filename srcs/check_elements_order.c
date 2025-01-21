/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_order.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:28:22 by wzeraig           #+#    #+#             */
/*   Updated: 2025/01/21 14:04:58 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_news(char c)
{
	return (c == 'N' || c == 'E' || c == 'W' || c == 'S' || c == '0'
		|| c == '1');
}
int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

int	check_cardinal_caracters(char *line_map)
{
	if ((line_map[0] == 'N' || line_map[0] == 'S') && line_map[1] == 'O')
		return (1);
	else if (line_map[0] == 'W' && line_map[1] == 'E')
		return (1);
	else if (line_map[0] == 'E' && line_map[1] == 'A')
		return (1);
	return (0);
}

int	check_textures_caracters(char *line_map)
{
	if (line_map[0] == 'F')
		return (1);
	else if (line_map[0] == 'C')
		return (1);
	return (0);
}

int	line_is_fullspace(char *line_map)
{
	size_t	i;

	i = 0;
	while (ft_isspace(line_map[i]))
		i++;
	if (i == ft_strlen(line_map))
		return (1);
	return (0);
}

int	line_is_spcnews(char *line_map)
{
	size_t	i;

	i = 0;
	while (ft_isspace(line_map[i]) || is_news(line_map[i]))
	{
		if (ft_isspace(line_map[i]))
			line_map[i] = '1';
		i++;
	}
	if (i == ft_strlen(line_map))
		return (1);
	return (0);
}

int	check_elements_order(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->map[i])
	{
		while (check_cardinal_caracters(cub3d->map[i])
			|| check_textures_caracters(cub3d->map[i]) || line_is_fullspace(cub3d->map[i]))
			i++;
		if (cub3d->map[i])
		{
			while (cub3d->map[i])
			{
				if (!line_is_spcnews(cub3d->map[i]))
					return (1);
				i++;
			}
		}
	}
	return (0);
}
