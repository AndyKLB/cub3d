/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:33:42 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/22 12:15:09 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// a revoir pour la gestion du strdup!!

// int	copy_element(char *element, char *line_map)
// {
// 	int	i;

// 	i = 0;
// 	while (ft_isspace(line_map[i]))
// 		i++;
// 	element = ft_strdup(line_map + i);
// 	if (!element)
// 		return (1);
// 	return (0);
// }

// int	get_floor_celling_textures(char *line_map, t_cub3d *cub3d, t_img *img)
// {
// 	if (line_map[0] == 'F')
// 		return (copy_element(img->floor, (line_map + 1)), 1);
// 	else if (line_map[0] == 'C')
// 		return (copy_element(img->celling, (line_map + 1)), 1);
// 	return (0);
// }

// int	get_wall_texture(char *line_map, t_cub3d *cub3d, t_img *img)
// {
// 	if ((line_map[0] == 'N' || line_map[0] == 'S') && line_map[1] == 'O')
// 	{
// 		if (line_map[0] == 'N')
// 			return (copy_element(img->north_element, (line_map + 2)), 1);
// 		else
// 			return (copy_element(img->south_element, (line_map + 2)), 1);
// 	}
// 	else if (line_map[0] == 'W' && line_map[1] == 'E')
// 		return (copy_element(img->west_element, (line_map + 2)), 1);
// 	else if (line_map[0] == 'E' && line_map[1] == 'A')
// 		return (copy_element(img->east_element, (line_map + 2)), 1);
// 	return (0);
// }

// get_chararacter_pos(char *line_map, t_cub3d *cub3d, t_data *data, int x)
// {
// 	int	i;

// 	i = 0;
// 	while (line_map[i])
// 	{
// 		if (line_map[i] == 'N')
// 		{
// 			data->player_x = x;
// 			data->player_y = i;
// 			data->player_direction = 'N';
// 		}
// 		else if (line_map[i] == 'S')
// 		{
// 			data->player_x = x;
// 			data->player_y = i;
// 			data->player_direction = 'S';
// 		}
// 		else if (line_map[i] == 'W')
// 		{
// 			data->player_x = x;
// 			data->player_y = i;
// 			data->player_direction = 'W';
// 		}
// 		else if (line_map[i] == 'E')
// 		{
// 			data->player_x = x;
// 			data->player_y = i;
// 			data->player_direction = 'E';
// 		}
// 	}
// }

// int	get_texture(t_cub3d *cub3d, t_img *img, t_data *data)
// {
// 	int	i;

// 	i = -1;
// 	while (cub3d->map[++i])
// 	{
// 		if (get_wall_texture(cub3d->map[i], cub3d, img))
// 			continue ;
// 		else if (get_floor_celling_textures(cub3d->map[i], cub3d, img))
// 			continue ;
// 		get_chararacter_pos(cub3d->map[i], cub3d, data, i);
// 	}
// }

int	data_init(char *path, t_cub3d *cub3d)
{
	if (!path || !*path)
		return (1);
	cub3d->path = path;
	cub3d->buff = NULL;
	cub3d->line = NULL;
	cub3d->map = NULL;
	return (0);
}