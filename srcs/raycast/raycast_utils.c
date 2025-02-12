/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:36:02 by wzeraig           #+#    #+#             */
/*   Updated: 2025/02/12 12:52:07 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	initialize_wall_draw(t_ray *ray)
{
	if (ray->hit_side == 0)
		ray->perp_wall_dist = ray->side_dist[X] - ray->delta_dist[X];
	else
		ray->perp_wall_dist = ray->side_dist[Y] - ray->delta_dist[Y];
	ray->line_height = (int)(WIN_H / ray->perp_wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + WIN_H / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_H / 2;
	if (ray->draw_end >= WIN_H)
		ray->draw_end = WIN_H - 1;
	if (ray->hit_side == 0)
	{
		if (ray->ray_dir[X] < 0)
			ray->texture_index = WEST;
		else
			ray->texture_index = EAST;
	}
	else
	{
		if (ray->ray_dir[Y] > 0)
			ray->texture_index = SOUTH;
		else
			ray->texture_index = NORTH;
	}
}

void	render_wall_pixels(t_cub3d *cub3d, t_ray *ray, int x, int **buffer)
{
	if (ray->hit_side == 0)
		ray->wall_hit_x = ray->pos[Y] + ray->perp_wall_dist * ray->ray_dir[Y];
	else
		ray->wall_hit_x = ray->pos[X] + ray->perp_wall_dist * ray->ray_dir[X];
	ray->wall_hit_x -= floor(ray->wall_hit_x);
	ray->texture[X] = (int)(ray->wall_hit_x * (double)IMG_SIZE);
	if (ray->hit_side == 0 && ray->ray_dir[X] > 0)
		ray->texture[X] = IMG_SIZE - ray->texture[X] - 1;
	if (ray->hit_side == 1 && ray->ray_dir[Y] < 0)
		ray->texture[X] = IMG_SIZE - ray->texture[X] - 1;
	ray->texture_step = 1.0 * IMG_SIZE / ray->line_height;
	ray->texture_position = (ray->draw_start - WIN_H / 2 + ray->line_height / 2)
		* ray->texture_step;
	ray->y = ray->draw_start - 1;
	while (++ray->y < ray->draw_end)
	{
		ray->texture[Y] = (int)ray->texture_position & (IMG_SIZE - 1);
		ray->texture_position += ray->texture_step;
		ray->color = cub3d->textures[(int)ray->texture_index][IMG_SIZE
			* ray->texture[Y] + ray->texture[X]];
		buffer[ray->y][x] = ray->color;
	}
}

void	perform_dda(t_cub3d *cub3d, t_ray *ray)
{
	ray->wall_hit = 0;
	while (ray->wall_hit == 0)
	{
		if (ray->side_dist[X] < ray->side_dist[Y])
		{
			ray->side_dist[X] += ray->delta_dist[X];
			ray->map_pos[X] += ray->step[X];
			ray->hit_side = 0;
		}
		else
		{
			ray->side_dist[Y] += ray->delta_dist[Y];
			ray->map_pos[Y] += ray->step[Y];
			ray->hit_side = 1;
		}
		if (ray->map_pos[Y] < 0.25 || ray->map_pos[X] < 0.25
			|| ray->map_pos[Y] > cub3d->map->height - 0.25
			|| ray->map_pos[X] > cub3d->map->width - 1.25)
			break ;
		if (cub3d->maps[ray->map_pos[Y]][ray->map_pos[X]] == '1')
			ray->wall_hit = 1;
	}
}

void	calculate_initial_side_distances(t_ray *ray)
{
	if (ray->ray_dir[X] < 0)
	{
		ray->step[X] = -1;
		ray->side_dist[X] = ((ray->pos[X] - ray->map_pos[X])
				* ray->delta_dist[X]);
	}
	else
	{
		ray->step[X] = 1;
		ray->side_dist[X] = ((ray->map_pos[X] + 1.0 - ray->pos[X])
				* ray->delta_dist[X]);
	}
	if (ray->ray_dir[Y] < 0)
	{
		ray->step[Y] = -1;
		ray->side_dist[Y] = ((ray->pos[Y] - ray->map_pos[Y])
				* ray->delta_dist[Y]);
	}
	else
	{
		ray->step[Y] = 1;
		ray->side_dist[Y] = ((ray->map_pos[Y] + 1.0 - ray->pos[Y])
				* ray->delta_dist[Y]);
	}
}

void	initialize_ray_direction(t_ray *ray, int x)
{
	ray->camera_offset[X] = 2 * x / (double)WIN_W - 1;
	ray->ray_dir[X] = ray->dir[X] + ray->plane[X] * ray->camera_offset[X];
	ray->ray_dir[Y] = ray->dir[Y] + ray->plane[Y] * ray->camera_offset[X];
	ray->map_pos[X] = (int)ray->pos[X];
	ray->map_pos[Y] = (int)ray->pos[Y];
	ray->delta_dist[X] = fabs(1 / ray->ray_dir[X]);
	ray->delta_dist[Y] = fabs(1 / ray->ray_dir[Y]);
}
