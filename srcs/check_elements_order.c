/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_order.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:28:22 by wzeraig           #+#    #+#             */
/*   Updated: 2025/02/17 16:08:17 by ankammer         ###   ########.fr       */
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

int	count_coltex(char **map)
{
	int	j;
	int	coltex;

	j = 0;
	coltex = 0;
	while (map[j])
	{
		if ((check_cardinal_caracters(map[j])
				|| check_textures_caracters(map[j])
				|| lineisspace(map[j])) && map[j])
			coltex++;
		j++;
	}
	return (coltex);
}

int	map_is_absent(char **map, int coltex, int *j)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while ((check_cardinal_caracters(map[i]) || check_textures_caracters(map[i])
			|| lineisspace(map[i])) && map[i])
	{
		if (!lineisspace(map[i]) && map[i])
			k++;
		i++;
		(*j) = k;
		if (!map[i])
		{
			if (coltex < 6)
				return (1);
			else if (coltex > 6)
				return (3);
			return (2);
		}
	}
	return (0);
}

int	check_elements_order(t_cub3d *cub3d)
{
	int	j;

	j = 0;
	cub3d->coltex = count_coltex(cub3d->maps);
	if (map_is_absent(cub3d->maps, cub3d->coltex, &j) == 1)
		return (ft_printf_fd(2, "%s\n%s", ERRCOLTEX, ERRNOMAP), 1);
	else if (map_is_absent(cub3d->maps, cub3d->coltex, &j) == 2)
		return (ft_printf_fd(2, "%s", ERRNOMAP), 1);
	while (cub3d->maps[j] && cub3d->coltex == 6)
	{
		if (line_is_spcnews(cub3d->maps[j]) && (cub3d->maps[j + 1]
				&& (check_cardinal_caracters(cub3d->maps[j + 1])
					|| check_textures_caracters(cub3d->maps[j + 1]))))
		{
			if (cub3d->coltex != 6)
				return (ft_printf_fd(2, "%s\n%s", ERRORDR, ERRCOLTEX), 1);
			return (ft_printf_fd(2, "%s\n", ERRORDR), 1);
		}
		if (!line_is_spcnews(cub3d->maps[j]))
			return (ft_printf_fd(2, "%s\n", ERRORUNKNOWN), 1);
		j++;
	}
	return (0);
}
