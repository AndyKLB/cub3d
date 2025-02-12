/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:00:23 by ankammer          #+#    #+#             */
/*   Updated: 2025/02/12 15:07:00 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	copy_element(char *textures, char **element)
{
	int	i;

	i = 0;
	if (*element)
	{
		free(*element);
		*element = NULL;
		return ;
	}
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
		return (copy_element((floor_cell_texture + i + 1), &cub3d->floor), 1);
	else if (floor_cell_texture[i] == 'C')
		return (copy_element((floor_cell_texture + i + 1), &cub3d->celling), 1);
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
			return (copy_element((wall_texture + i + 2), &cub3d->north_element),
				1);
		else
			return (copy_element((wall_texture + i + 2), &cub3d->south_element),
				1);
	}
	else if (wall_texture[i] == 'W' && wall_texture[i + 1] == 'E')
		return (copy_element((wall_texture + i + 2), &cub3d->west_element), 1);
	else if (wall_texture[i] == 'E' && wall_texture[i + 1] == 'A')
		return (copy_element((wall_texture + i + 2), &cub3d->east_element), 1);
	return (0);
}

int	check_texture_init(t_cub3d *cub3d)
{
	if (!cub3d->south_element || check_dir_textures(&cub3d->south_element,
			cub3d))
		return (1);
	if (!cub3d->north_element || check_dir_textures(&cub3d->north_element,
			cub3d))
		return (1);
	if (!cub3d->west_element || check_dir_textures(&cub3d->west_element, cub3d))
		return (1);
	if (!cub3d->east_element || check_dir_textures(&cub3d->east_element, cub3d))
		return (1);
	if (!cub3d->floor || check_nbr_value(cub3d->floor)
		|| check_value(cub3d->floor, 1, cub3d))
		return (1);
	if (!cub3d->celling || check_nbr_value(cub3d->celling)
		|| check_value(cub3d->celling, 0, cub3d))
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
	remove_comma(cub3d->floor);
	remove_comma(cub3d->celling);
	if (check_texture_init(cub3d))
	{
		if (cub3d->coltex > 6)
			return (free_superstrs(&tmp_texture), msg_error(ERRDUPTEX, cub3d), 1);
		return (free_supetstrs(&tmp_texture), msg_error(ERRCOLTEX, cub3d), 1);
	}
	return (0);
}
