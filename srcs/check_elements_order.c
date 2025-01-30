/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_order.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:28:22 by wzeraig           #+#    #+#             */
/*   Updated: 2025/01/30 12:06:59 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_cardinal_caracters(char *line_map)
{
	int	i;

	i = 0;
	while (ft_isspace(line_map[i]))
		i++;
	if ((line_map[i] == 'N' || line_map[i] == 'S') && line_map[i + 1] == 'O')
		return (1);
	else if (line_map[i] == 'W' && line_map[i + 1] == 'E')
		return (1);
	else if (line_map[i] == 'E' && line_map[i + 1] == 'A')
		return (1);
	return (0);
}

int	check_textures_caracters(char *line_map)
{
	int	i;

	i = 0;
	while (ft_isspace(line_map[i]))
		i++;
	if (line_map[i] == 'F')
		return (1);
	else if (line_map[i] == 'C')
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
		i++;
	if (i == ft_strlen(line_map))
		return (1);
	return (0);
}

int	check_elements_order(t_cub3d *cub3d)
{
	int	i;
	int	j;
	
	j = 0;
	i = 0;
	while ((check_cardinal_caracters(cub3d->maps[i])
			|| check_textures_caracters(cub3d->maps[i])
			|| line_is_fullspace(cub3d->maps[i])) && cub3d->maps[i])
	{
		if(!line_is_fullspace(cub3d->maps[i]) && cub3d->maps[i])
			j++;
		i++;
		if (!cub3d->maps[i])
			return (2);
	}
	if (j != 6)
		return (2);
	while (cub3d->maps[i])
	{
		if (!line_is_spcnews(cub3d->maps[i]))
			return (1);
		i++;
	}
	return (0);
}
