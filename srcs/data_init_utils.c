/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:33:42 by ankammer          #+#    #+#             */
/*   Updated: 2025/02/12 13:33:45 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_cub3d_struct(t_cub3d **cub3d)
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
}

void	init_map_struct(t_map **map)
{
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

void	init_img_struct(t_img **img)
{
	(*img)->mlx_img = NULL;
	(*img)->addr = 0;
	(*img)->bpp = 0;
	(*img)->line_len = 0;
	(*img)->endian = 0;
	(*img)->img_width = 0;
	(*img)->img_height = 0;
}

void	init_ray_struct_2(t_ray **ray)
{
	(*ray)->move[0] = 0;
	(*ray)->move[1] = 0;
	(*ray)->side_dist[0] = 0;
	(*ray)->side_dist[1] = 0;
	(*ray)->delta_dist[0] = 0;
	(*ray)->delta_dist[1] = 0;
	(*ray)->ray_dir[0] = 0;
	(*ray)->ray_dir[1] = 0;
	(*ray)->camera_offset[0] = 0;
	(*ray)->camera_offset[1] = 0;
	(*ray)->plane[0] = 0;
	(*ray)->plane[1] = 0;
	(*ray)->pos[0] = 0;
	(*ray)->pos[1] = 0;
	(*ray)->map_pos[0] = 0;
	(*ray)->map_pos[1] = 0;
	(*ray)->texture[0] = 0;
	(*ray)->texture[1] = 0;
	(*ray)->step[0] = 0;
	(*ray)->step[1] = 0;
}

void	init_ray_struct(t_ray **ray)
{
	init_ray_struct_2(ray);
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
