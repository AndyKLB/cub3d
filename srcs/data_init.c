/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:33:42 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/22 16:55:08 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	set_position(int x, int y, char direction, t_data *data)
{
	data->player_x = x;
	data->player_y = y;
	data->player_direction = direction;
}

void	get_chararacter_pos(char **map, t_data *data) // ajouter un break
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				set_position(j, i, 'N', data);
			else if (map[i][j] == 'S')
				set_position(j, i, 'S', data);
			else if (map[i][j] == 'W')
				set_position(j, i, 'W', data);
			else if (map[i][j] == 'E')
				set_position(j, i, 'E', data);
			j++;
		}
		i++;
	}
}

// a revoir pour la gestion du strdup!!
// init strdup incorrect a revoir!!

void	copy_element(char *line_map, char *element)
{
	int	i;

	i = 0;
	while (ft_isspace(line_map[i]))
		i++;
	element = ft_strdup((line_map + i));
	if (!element)
		element = NULL;
	return ;
}

int	get_floor_celling_textures(char *line_map, t_data *data)
{
	int	i;

	i = 0;
	while (ft_isspace(line_map[i]))
		i++;
	if (line_map[i] == 'F')
		return (copy_element((line_map), data->floor), 1);
	else if (line_map[i] == 'C')
		return (copy_element((line_map), data->celling), 1);
	return (0);
}

int	get_wall_texture(char *line_map, t_data *data)
{
	int	i;

	i = 0;
	while (ft_isspace(line_map[i]))
		i++;
	if ((line_map[i] == 'N' || line_map[i] == 'S') && line_map[i + 1] == 'O')
	{
		if (line_map[i] == 'N')
			return (copy_element((line_map), data->north_element), 1);
		else
			return (copy_element((line_map), data->south_element), 1);
	}
	else if (line_map[i] == 'W' && line_map[i + 1] == 'E')
		return (copy_element((line_map), data->west_element), 1);
	else if (line_map[i] == 'E' && line_map[i + 1] == 'A')
		return (copy_element((line_map), data->east_element), 1);
	return (0);
}

int	check_texture_init(t_data *data)
{
	if (!data->south_element)
		return (1);
	if (!data->north_element)
		return (1);
	if (!data->west_element)
		return (1);
	if (!data->east_element)
		return (1);
	if (!data->floor)
		return (1);
	if (!data->celling)
		return (1);
	return (0);
}

int	get_texture(t_cub3d *cub3d, t_data *data)
{
	int	i;

	i = -1;
	get_chararacter_pos(cub3d->map, data);
	while (cub3d->textures_info[++i])
	{
		if (!get_wall_texture(cub3d->textures_info[i], data)
			&& !get_floor_celling_textures(cub3d->textures_info[i], data))
			break ;
	}
	if (check_texture_init(data))
		return (msg_error(ERRTEXT, cub3d), 1);
	return (0);
}

int	data_init(char *path, t_cub3d *cub3d)
{
	if (!path || !*path)
		return (1);
	cub3d->path = path;
	cub3d->buff = NULL;
	cub3d->line = NULL;
	cub3d->map = NULL;
	cub3d->textures_info = NULL;
	return (0);
}