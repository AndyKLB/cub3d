/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:00:23 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/28 11:50:31 by ankammer         ###   ########.fr       */
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
// probleme avec square map espace EA semble poser probleme " textures/....."

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

int	check_nbr_value(char *floor_or_celling)
{
	int	i;
	int	nb_spc;
	int	is_not_digit;

	is_not_digit = 0;
	nb_spc = 0;
	i = 0;
	while (floor_or_celling[i] || ft_isspace(floor_or_celling[i]))
	{
		if (!ft_isdigit(floor_or_celling[i])
			&& !ft_isspace(floor_or_celling[i]))
			is_not_digit++;
		if (floor_or_celling[i] == ' ')
			nb_spc++;
		i++;
	}
	if (nb_spc != 2 || is_not_digit)
		return (1);
	return (0);
}
void	go_to_end(int *i, char *dir_path, char c)
{
	while (dir_path[*i])
		(*i)++;
	while (dir_path[*i] != c && *i > 0)
		(*i)--;
}

// 1 pourquoi forbidden.cub bad ? a revoir
int	check_dir_textures(char **dir_path)
{
	DIR		*dir;
	int		i;
	char	*dir_strim;

	if (!*dir_path)
		return (1);
	i = 0;
	*dir_path = ft_strtrim_free(*dir_path, " ");
	go_to_end(&i, *dir_path, '/');
	dir_strim = ft_rsubstr(*dir_path, i, (ft_strlen(*dir_path)));
	if (!dir_strim)
		return (1);
	dir = opendir(dir_strim);
	if (!dir)
		return (free(dir_strim), 1);
	closedir(dir);
	free(dir_strim);
	i = 0;
	go_to_end(&i, *dir_path, '.');
	if (ft_strictcmp((*dir_path + i), ".xpm"))
		return (printf("%s\n", (*dir_path + i)), 1);
	return (0);
}

int	check_texture_init(t_cub3d *cub3d) // 1
{
	if (!cub3d->south_element || check_dir_textures(&cub3d->south_element))
		return (1);
	if (!cub3d->north_element || check_dir_textures(&cub3d->north_element))
		return (1);
	if (!cub3d->west_element || check_dir_textures(&cub3d->west_element))
		return (1);
	if (!cub3d->east_element || check_dir_textures(&cub3d->east_element))
		return (1);
	if (!cub3d->floor || check_nbr_value(cub3d->floor))
		return (1);
	if (!cub3d->celling || check_nbr_value(cub3d->celling))
		return (1);
	return (0);
}

void	remove_comma(char *element)
{
	int	i;

	i = 0;
	if (!element)
		return ;
	while (element[i])
	{
		if (element[i] == ',')
			element[i] = ' ';
		i++;
	}
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
		return (msg_error(ERRTEXT, cub3d), 1);
	return (0);
}
