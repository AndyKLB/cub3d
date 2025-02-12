/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:33:42 by ankammer          #+#    #+#             */
/*   Updated: 2025/02/12 14:27:48 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void init_cub3d_struct(t_cub3d **cub3d)
{
	(*cub3d)->maps = NULL;
	(*cub3d)->south_element = NULL;
	(*cub3d)->north_element = NULL;
	(*cub3d)->west_element = NULL;
	(*cub3d)->east_element = NULL;
	(*cub3d)->floor = NULL;
	(*cub3d)->celling = NULL;
	(*cub3d)->player_direction = 0;
	(*cub3d)->textures = NULL;
	(*cub3d)->mlx = NULL;
	(*cub3d)->win = NULL;
	(*cub3d)->coltex = 0;
}

void init_map_struct(t_map **map)
{

	//(*map)->grid = NULL;

	(*map)->width = 0;
	(*map)->height = 0;
	(*map)->fcolor_i = 0;
	(*map)->ccolor_i = 0;
	(*map)->f_tab[0] = -1;
	(*map)->f_tab[1] = -1;
	(*map)->f_tab[2] = -1;
	(*map)->c_tab[0] = -1;
	(*map)->c_tab[1] = -1;
	(*map)->c_tab[2] = -1;
}

void init_img_struct(t_img **img)
{
	(*img)->mlx_img = NULL;
	(*img)->addr = 0;
	(*img)->bpp = 0;
	(*img)->line_len = 0;
	(*img)->endian = 0;
	(*img)->img_width = 0;
	(*img)->img_height = 0;
}

void init_ray_struct(t_ray **ray) // le bzero n;est pas effectif
{
	ft_bzero((*ray)->pos, 2);
	ft_bzero((*ray)->ray_dir, 2);
	ft_bzero((*ray)->plane, 2);
	ft_bzero((*ray)->camera_offset, 2);
	ft_bzero((*ray)->ray_dir, 2);
	ft_bzero((*ray)->side_dist, 2);
	ft_bzero((*ray)->delta_dist, 2);
	ft_bzero((*ray)->map_pos, 2);
	ft_bzero((*ray)->step, 2);
	ft_bzero((*ray)->texture, 2);
	// ft_bzero((*ray)->move, 2);
	(*ray)->move[0] = 0;
	(*ray)->move[1] = 0;
	(*ray)->rotate = 0;
	(*ray)->moved = 0;
	(*ray)->line_height = 0;
	(*ray)->draw_start = 0;
	(*ray)->draw_end = 0;
	(*ray)->hit_side = 0;
	(*ray)->wall_hit = 0;
	(*ray)->perp_wall_dist = 0;
	(*ray)->texture_index = 0;
	(*ray)->wall_hit_x = 0;
	(*ray)->texture_step = 0;
	(*ray)->texture_position = 0;
	(*ray)->color = 0;
	(*ray)->y = 0;
}

int data_init(t_cub3d *cub3d, t_img *img, t_map *map, t_ray *ray)
{
	cub3d->map = map;
	cub3d->img = img;
	cub3d->ray = ray;
	init_cub3d_struct(&cub3d);
	init_map_struct(&map);
	init_img_struct(&img);
	init_ray_struct(&ray);
	return (0);
}
void mapformat(t_cub3d *cub3d)
{
	int j;
	int i;

	i = 0;
	j = 0;
	while (cub3d->maps[j])
	{
		while (cub3d->maps[j][i])
		{
			i++;
		}
		if (cub3d->map->width < i)
			cub3d->map->width = i;
		j++;
		i = 0;
	}
	cub3d->map->height = j;
}