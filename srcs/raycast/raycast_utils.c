/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:36:02 by wzeraig           #+#    #+#             */
/*   Updated: 2025/02/11 11:00:40 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// void initialize_wall_draw(t_ray *ray)
// {
//     // if (ray->wall_hit == 0)
//     //     ray->perp_wall_dist = ray->side_dist[X] - ray->delta_dist[X];
//     // else
//     //     ray->perp_wall_dist = ray->side_dist[Y] - ray->delta_dist[Y];

//     // ray->line_height = (int)(WIN_H / ray->perp_wall_dist);
//     // ray->draw_start = (-(ray->line_height) / 2 + WIN_H / 2);
//     // if (ray->draw_start < 0)
//     //     ray->draw_start = 0;
//     // ray->draw_end = (ray->line_height / 2 + WIN_H / 2);
//     // if (ray->draw_end >= WIN_H)
//     //     ray->draw_end = WIN_H - 1;

//     // if (ray->hit_side == 0)
//     // {
//     //     if (ray->ray_dir[X] < 0)
//     //         ray->texture_index = WEST;
//     //     else
//     //         ray->texture_index = EAST;
//     // }
//     // else
//     // {
//     //     if (ray->ray_dir[Y] > 0)
//     //         ray->texture_index = SOUTH;
//     //     else
//     //         ray->texture_index = NORTH;
//     // }
//     if (ray->hit_side == 0) // si on a touche un mur vertical, on prend x logique. c cette donne qui va nous dire a quel distance on est du mur.
//         ray->perp_wall_dist = ray->side_dist[X] - ray->delta_dist[X];
//     else
//         ray->perp_wall_dist = ray->side_dist[Y] - ray->delta_dist[Y];
//     ray->line_height = (int)(WIN_H / ray->perp_wall_dist);
//     ray->draw_start = -(ray->line_height) / 2 + WIN_H / 2;
//     if (ray->draw_start < 0)
//         ray->draw_start = 0;
//     ray->draw_end = ray->line_height / 2 + WIN_H / 2;
//     if (ray->draw_end >= WIN_H)
//         ray->draw_end = WIN_H - 1;
//     if (ray->hit_side == 0)
//     {
//         if (ray->ray_dir[X] < 0)
//             ray->texture_index = WEST;
//         else
//             ray->texture_index = EAST;
//     }
//     else
//     {
//         if (ray->ray_dir[Y] > 0)
//             ray->texture_index = SOUTH;
//         else
//             ray->texture_index = NORTH;
//     }
// }

// void render_wall_pixels(t_cub3d *cub3d, t_ray *ray, int x, int **buffer)
// {
//     if (ray->hit_side == 0)
//         ray->wall_hit_x = ray->pos[Y] + ray->perp_wall_dist * ray->ray_dir[Y];
//     else
//         ray->wall_hit_x = ray->pos[X] + ray->perp_wall_dist * ray->ray_dir[X];
//     ray->wall_hit_x -= floor(ray->wall_hit_x);
//     ray->texture[0] = (int)(ray->wall_hit_x * (double)IMG_SIZE);
//     if (ray->hit_side == 0 && ray->ray_dir[X] > 0)
//         ray->texture[0] = IMG_SIZE - ray->texture[0] - 1;
//     if (ray->hit_side == 1 && ray->ray_dir[Y] < 0)
//         ray->texture[0] = IMG_SIZE - ray->texture[0] - 1;
//     ray->texture_step = 1.0 * IMG_SIZE / ray->line_height;
//     ray->texture_position = (ray->draw_start - WIN_H / 2 + ray->line_height / 2) * ray->texture_step;
//     ray->y = ray->draw_start - 1;
//     while (++ray->y < ray->draw_end)
//     {
//         ray->texture[Y] = (int)ray->texture_position & (IMG_SIZE - 1);
//         ray->texture_position += ray->texture_step;
//         ray->color = cub3d->textures[ray->texture_index][IMG_SIZE * ray->texture[Y] + ray->texture[0]];
//         buffer[ray->y][x] = ray->color;
//     }
//     // if (ray->hit_side == 0)
//     //     ray->wall_hit_x = ray->pos[Y] + ray->perp_wall_dist * ray->ray_dir[Y];
//     // else
//     //     ray->wall_hit_x = ray->pos[X] + ray->perp_wall_dist * ray->ray_dir[X];

//     // ray->wall_hit_x -= floor(ray->wall_hit_x);
//     // ray->texture[X] = (int)(ray->wall_hit_x * (double)IMG_SIZE);

//     // if (ray->hit_side == 0 && ray->ray_dir[X] > 0)
//     //     ray->texture[X] = IMG_SIZE - ray->texture[X] - 1;
//     // if (ray->hit_side == 1 && ray->ray_dir[Y] < 0)
//     //     ray->texture[X] = IMG_SIZE - ray->texture[X] - 1;

//     // ray->texture_step =  (double)IMG_SIZE / (double)ray->line_height;
//     // ray->texture_position = (ray->draw_start - WIN_H / 2 + ray->line_height / 2) * ray->texture_step;

//     // for (ray->y = ray->draw_start; ray->y < ray->draw_end; ray->y++)
//     // {
//     //     ray->texture[Y] = (int)ray->texture_position & (IMG_SIZE - 1);
//     //     ray->texture_position += ray->texture_step;
//     //     buffer[ray->y][x] = cub3d->textures[ray->texture_index][IMG_SIZE * ray->texture[Y] + ray->texture[X]]; //tu dis que le tableau de char en 2d, = la texture adequate south north ect, et par la taille de la texture. * img_size
//     // }
// }

// void perform_dda(t_cub3d *cub3d, t_ray *ray)
// {
//     while (!ray->wall_hit)
//     {
//         if (ray->side_dist[X] < ray->side_dist[Y])
//         {
//             ray->side_dist[X] += ray->delta_dist[X];
//             ray->map_pos[X] += ray->step[X];
//             ray->hit_side = 0;
//         }
//         else
//         {
//             ray->side_dist[Y] += ray->delta_dist[Y];
//             ray->map_pos[Y] += ray->step[Y];
//             ray->hit_side = 1;
//         }
//         if (cub3d->maps[ray->map_pos[Y]][ray->map_pos[X]] == '1')
//             ray->wall_hit = 1;
//     }
// }

// void calculate_initial_side_distances(t_ray *ray)
// {
//     int coord = 0;
//     while (coord < 2)
//     {
//         if (ray->ray_dir[coord] < 0)
//         {
//             ray->step[coord] = -1;
//             ray->side_dist[coord] = (ray->pos[coord] - ray->map_pos[coord]) * ray->delta_dist[coord];
//         }
//         else
//         {
//             ray->step[coord] = 1;
//             ray->side_dist[coord] = (ray->map_pos[coord] + 1.0 - ray->pos[coord]) * ray->delta_dist[coord];
//         }
//         coord++;
//     }
// }

// void initialize_ray_direction(t_ray *ray, int x)
// {
//     ray->camera_offset[X] = 2 * x / (double)WIN_W - 1;
//     ray->ray_dir[X] = ray->dir[X] + ray->plane[X] * ray->camera_offset[X];
//     ray->ray_dir[Y] = ray->dir[Y] + ray->plane[Y] * ray->camera_offset[X];

//     ray->map_pos[X] = (int)ray->pos[X];
//     ray->map_pos[Y] = (int)ray->pos[Y];

//     ray->delta_dist[X] = fabs(1 / ray->ray_dir[X]);
//     ray->delta_dist[Y] = fabs(1 / ray->ray_dir[Y]);
// }
void initialize_wall_draw(t_ray *ray)
{
	if (ray->hit_side == 0) // si on a touche un mur vertical, on prend x logique. c cette donne qui va nous dire a quel distance on est du mur.
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
			ray->texture_position = WEST;
		else
			ray->texture_position = EAST;
	}
	else
	{
		if (ray->ray_dir[Y] > 0)
			ray->texture_position = SOUTH;
		else
			ray->texture_position = NORTH;
	}
}

void render_wall_pixels(t_cub3d *cub3d, t_ray *ray, int x, int **buffer)
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
	ray->texture_position = (ray->draw_start - WIN_H / 2 + ray->line_height / 2) * ray->texture_step;
	ray->y = ray->draw_start - 1;
	while (++ray->y < ray->draw_end)
	{
		ray->texture[Y] = (int)ray->texture_position & (IMG_SIZE - 1);
		ray->texture_position += ray->texture_step;
		ray->color = cub3d->textures[(int)ray->texture_position][IMG_SIZE * ray->texture[Y] + ray->texture[X]];
		buffer[ray->y][x] = ray->color;
	}
}

void perform_dda(t_cub3d *cub3d, t_ray *ray)
{
	ray->wall_hit = 0;
	while (ray->wall_hit) // tant que jai pas touche de mur il avance case par case
	{
		if (ray->side_dist[X] < ray->side_dist[Y]) // l'intersection la plus proche c'est verticla ou horizontal
		{
			ray->side_dist[X] += ray->delta_dist[X];
			ray->map_pos[X] += ray->step[X];
			ray->wall_hit = 0;
		}
		else
		{
			ray->side_dist[Y] += ray->delta_dist[Y];
			ray->map_pos[Y] += ray->step[Y];
			ray->wall_hit = 1;
		}
		if (ray->map_pos[Y] < 0.25 || ray->map_pos[X] < 0.25 || ray->map_pos[Y] > cub3d->map->height - 0.25 || ray->map_pos[X] > cub3d->map->width - 1.25) // protection de sortie.
			break;
		if (cub3d->maps[ray->map_pos[Y]][ray->map_pos[X]] == '1')
			ray->wall_hit = 1;
	} // on fais avance le rayon dans la bonne direction, via le sens de raystep calcule par rapport a la direction du rayon
}

void calculate_initial_side_distances(t_ray *ray)
{
	if (ray->ray_dir[X] < 0) // gauche on calcul la distance entre le joueur et le bord gauche. * delta_distx pour obtenir la distance physique
	{
		ray->step[X] = -1;
		ray->side_dist[X] = ((ray->pos[X] - ray->map_pos[X]) * ray->delta_dist[X]);
	} // rayside_dist = distance jusqua la prochaine ligne vertical .
	else
	{
		ray->step[X] = 1;
		ray->side_dist[X] = ((ray->map_pos[X] + 1.0 - ray->pos[X]) * ray->delta_dist[X]);
	}
	if (ray->ray_dir[Y] < 0)
	{
		ray->step[Y] = -1;
		ray->side_dist[Y] = ((ray->pos[Y] - ray->map_pos[Y]) * ray->delta_dist[Y]);
	}
	else
	{
		ray->step[Y] = 1;
		ray->side_dist[Y] = ((ray->map_pos[Y] + 1.0 - ray->pos[Y]) * ray->delta_dist[Y]);
	}
}

void initialize_ray_direction(t_ray *ray, int x)
{
	ray->camera_offset[X] = 2 * x / (double)WIN_W - 1;					   // transforme x en une valeur entre -1 et 1 (angle de vue)
	ray->ray_dir[X] = ray->dir[X] + ray->plane[X] * ray->camera_offset[X]; // donne la direction du rayon en x
	ray->ray_dir[Y] = ray->dir[Y] + ray->plane[Y] * ray->camera_offset[X]; // langle de vue c pour couvrir toute la colone de vue FOV 66degres.
	ray->map_pos[X] = (int)ray->pos[X];									   // des coordonne flotante faut le place sur la map_pos en entier.
	ray->map_pos[Y] = (int)ray->pos[Y];									   // depaet du rayon.
	ray->delta_dist[X] = fabs(1 / ray->ray_dir[X]);						   // on regarde la premieere intersection touche. on divise le rayon pas a pas, on verifie si cest une colone ou une ligne, pour savoir on verifie si deltaX est plus grand que y, ca veut dire quil a plus voyage en x  qu'en y du coup cest vertical
	ray->delta_dist[Y] = fabs(1 / ray->ray_dir[Y]);						   // calcul de distance pour savoir la distance a parcourir pour atteindre la prochaine ligne.
}
// distance entre deux mur horiwzontaux et deux mur verticaux.
