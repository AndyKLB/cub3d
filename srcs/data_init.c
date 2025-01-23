/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:33:42 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/23 12:15:33 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	set_position(int x, int y, char direction, t_cub3d *cub3d)
{
	cub3d->player_x = x;
	cub3d->player_y = y;
	cub3d->player_direction = direction;
}

void	get_chararacter_pos(char **map, t_cub3d *cub3d) // ajouter un break
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				set_position(j, i, 'N', cub3d);
			else if (map[i][j] == 'S')
				set_position(j, i, 'S', cub3d);
			else if (map[i][j] == 'W')
				set_position(j, i, 'W', cub3d);
			else if (map[i][j] == 'E')
				set_position(j, i, 'E', cub3d);
			j++;
		}
		i++;
	}
}

// a revoir pour la gestion du strdup!!
// init strdup incorrect a revoir!!

void	copy_element(char *textures, char **element)
{
	int	i;

	i = 0;
	while (ft_isspace(textures[i]))
		i++;
	*element = ft_strdup((textures + i));
	if (!*element)
		*element = NULL;
	return ;
}

int	get_floor_celling_textures(char *floor_cell_texture, t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (ft_isspace(floor_cell_texture[i]))
		i++;
	if (floor_cell_texture[i] == 'F')
		return (copy_element((floor_cell_texture), &cub3d->floor), 1);
	else if (floor_cell_texture[i] == 'C')
		return (copy_element((floor_cell_texture), &cub3d->celling), 1);
	return (0);
}

int	get_wall_texture(char *wall_texture, t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (ft_isspace(wall_texture[i]))
		i++;
	if ((wall_texture[i] == 'N' || wall_texture[i] == 'S') && wall_texture[i
		+ 1] == 'O')
	{
		if (wall_texture[i] == 'N')
			return (copy_element((wall_texture), &cub3d->north_element), 1);
		else
			return (copy_element((wall_texture), &cub3d->south_element), 1);
	}
	else if (wall_texture[i] == 'W' && wall_texture[i + 1] == 'E')
		return (copy_element((wall_texture), &cub3d->west_element), 1);
	else if (wall_texture[i] == 'E' && wall_texture[i + 1] == 'A')
		return (copy_element((wall_texture), &cub3d->east_element), 1);
	return (0);
}

int	check_texture_init(t_cub3d *cub3d)
{
	if (!cub3d->south_element)
		return (1);
	if (!cub3d->north_element)
		return (1);
	if (!cub3d->west_element)
		return (1);
	if (!cub3d->east_element)
		return (1);
	if (!cub3d->floor)
		return (1);
	if (!cub3d->celling)
		return (1);
	return (0);
}

int	get_texture(t_cub3d *cub3d, char **tmp_texture)
{
	int	i;

	i = -1;
	get_chararacter_pos(cub3d->maps, cub3d);
	while (tmp_texture[++i])
	{
		if (!get_wall_texture(tmp_texture[i], cub3d)
			&& !get_floor_celling_textures(tmp_texture[i], cub3d))
			break ;
	}
	if (check_texture_init(cub3d))
		return (msg_error(ERRTEXT), 1);
	return (0);
}

int	data_init(char *path, t_cub3d *cub3d)
{
	if (!path || !*path)
		return (1);
	cub3d->maps = NULL;
	cub3d->south_element = NULL;
	cub3d->north_element = NULL;
	cub3d->west_element = NULL;
	cub3d->east_element = NULL;
	cub3d->floor = NULL;
	cub3d->celling = NULL;
	cub3d->player_direction = 0;
	cub3d->player_x = 0;
	cub3d->player_y = 0;
	cub3d->win_height = 0;
	cub3d->win_width = 0;
	cub3d->map = NULL;
	cub3d->img = NULL;
	return (0);
}
