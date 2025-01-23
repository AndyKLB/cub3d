/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:33:42 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/23 14:06:33 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_cub3d_struct(t_cub3d **cub3d, t_map **map, t_img **img)
{
	(*cub3d)->maps = NULL;
	(*cub3d)->south_element = NULL;
	(*cub3d)->north_element = NULL;
	(*cub3d)->west_element = NULL;
	(*cub3d)->east_element = NULL;
	(*cub3d)->floor = NULL;
	(*cub3d)->celling = NULL;
	(*cub3d)->player_direction = 0;
	(*cub3d)->player_x = 0;
	(*cub3d)->player_y = 0;
	(*cub3d)->win_height = 0;
	(*cub3d)->win_width = 0;
	(*cub3d)->map = *map;
	(*cub3d)->img = *img;
}
void	init_map_struct(t_map **map)
{
	(*map)->line = NULL;
	(*map)->count = 0;
	(*map)->countline = 0;
	(*map)->index = 0;
}
void	init_img_struct(t_img **img)
{
	(*img)->width = 0;
	(*img)->height = 0;
	(*img)->line_length = 0;
}

int	data_init(t_cub3d *cub3d, t_img *img, t_map *map)
{


	init_cub3d_struct(&cub3d, &map, &img);
	init_map_struct(&cub3d->map);
	init_img_struct(&cub3d->img);
	return (0);
}
