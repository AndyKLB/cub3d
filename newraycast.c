/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newraycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:36:02 by wzeraig           #+#    #+#             */
/*   Updated: 2025/01/30 15:36:15 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Initialise les variables de dessin du mur en fonction de l'intersection du rayon.
 */
void	start_draw(t_ray *ray)
{
    if (ray->side == 0)
        ray->perp_wall_dist = ray->side_dist[X] - ray->delta_dist[X];
    else
        ray->perp_wall_dist = ray->side_dist[Y] - ray->delta_dist[Y];

    ray->line_height = (int)(WIN_H / ray->perp_wall_dist);
    ray->draw_start = (-(ray->line_height) / 2 + WIN_H / 2);
    if (ray->draw_start < 0)
        ray->draw_start = 0;
    ray->draw_end = (ray->line_height / 2 + WIN_H / 2);
    if (ray->draw_end >= WIN_H)
        ray->draw_end = WIN_H - 1;

    // Définition du numéro de texture en fonction du côté touché
    if (ray->side == 0)
        ray->texture_index = (ray->ray_dir[X] < 0) ? WE : EA;
    else
        ray->texture_index = (ray->ray_dir[Y] > 0) ? SO : NO;
}

/**
 * Dessine les pixels du mur en fonction de la texture et les stocke dans le buffer.
 */
void	draw_pixels(t_cub3d *cub3d, t_ray *ray, int x, int **buffer)
{
    ray->wall_x = (ray->side == 0) ? (ray->pos[Y] + ray->perp_wall_dist * ray->ray_dir[Y])
                                   : (ray->pos[X] + ray->perp_wall_dist * ray->ray_dir[X]);
    ray->wall_x -= floor(ray->wall_x);
    ray->texture[X] = (int)(ray->wall_x * (double)IMG_SIZE);
    if ((ray->side == 0 && ray->ray_dir[X] > 0) || (ray->side == 1 && ray->ray_dir[Y] < 0))
        ray->texture[X] = IMG_SIZE - ray->texture[X] - 1;

    ray->texture_step = 1.0 * IMG_SIZE / ray->line_height;
    ray->texture_pos = (ray->draw_start - WIN_H / 2 + ray->line_height / 2) * ray->texture_step;

    for (ray->y = ray->draw_start; ray->y < ray->draw_end; ray->y++)
    {
        ray->texture[Y] = (int)ray->texture_pos & (IMG_SIZE - 1);
        ray->texture_pos += ray->texture_step;
        buffer[ray->y][x] = cub3d->textures[ray->texture_index][IMG_SIZE * ray->texture[Y] + ray->texture[X]];
    }
}

/**
 * Implémente l'algorithme DDA pour trouver l'intersection du rayon avec un mur.
 */
void	dda_algorithm(t_cub3d *cub3d, t_ray *ray)
{
    while (!ray->hit)
    {
        if (ray->side_dist[X] < ray->side_dist[Y])
        {
            ray->side_dist[X] += ray->delta_dist[X];
            ray->map[X] += ray->step[X];
            ray->side = 0;
        }
        else
        {
            ray->side_dist[Y] += ray->delta_dist[Y];
            ray->map[Y] += ray->step[Y];
            ray->side = 1;
        }
        if (cub3d->map->grid[ray->map[Y]][ray->map[X]] == '1')
            ray->hit = 1;
    }
}

/**
 * Calcule la distance initiale aux prochaines intersections verticales et horizontales.
 */
void	calculate_side_dist(t_ray *ray)
{
    for (int axis = 0; axis < 2; axis++) {
        if (ray->ray_dir[axis] < 0)
        {
            ray->step[axis] = -1;
            ray->side_dist[axis] = (ray->pos[axis] - ray->map[axis]) * ray->delta_dist[axis];
        }
        else
        {
            ray->step[axis] = 1;
            ray->side_dist[axis] = (ray->map[axis] + 1.0 - ray->pos[axis]) * ray->delta_dist[axis];
        }
    }
}

/**
 * Initialise la direction du rayon pour une colonne spécifique à l'écran.
 */
void	initialize_ray_direction(t_ray *ray, int x)
{
    ray->camera[X] = 2 * x / (double)WIN_W - 1;
    ray->ray_dir[X] = ray->dir[X] + ray->plane[X] * ray->camera[X];
    ray->ray_dir[Y] = ray->dir[Y] + ray->plane[Y] * ray->camera[X];
    
    ray->map[X] = (int)ray->pos[X];
    ray->map[Y] = (int)ray->pos[Y];
    
    ray->delta_dist[X] = fabs(1 / ray->ray_dir[X]);
    ray->delta_dist[Y] = fabs(1 / ray->ray_dir[Y]);
}
