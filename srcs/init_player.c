/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:22:34 by wzeraig           #+#    #+#             */
/*   Updated: 2025/02/10 11:28:38 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void init_plane(t_ray *ray, char c)
{
	if (c == 'S')
	{
		ray->plane[0] = -0.66;
		ray->plane[1] = 0;
	}
	else if (c == 'N')
	{
		ray->plane[0] = 0.66;
		ray->plane[1] = 0;
	}
	else if (c == 'E')
	{
		ray->plane[0] = 0;
		ray->plane[1] = 0.66;
	}
	else if (c == 'W')
	{
		ray->plane[0] = 0;
		ray->plane[1] = -0.66;
	}
}

static void init_player(int y, int x, char c, t_ray *ray)
{
	ray->pos[0] = (double)x + 0.5;
	ray->pos[1] = (double)y + 0.5;
	if (c == 'S')
	{
		ray->dir[0] = 0;
		ray->dir[1] = 1;
	}
	else if (c == 'N')
	{
		ray->dir[0] = 0;
		ray->dir[1] = -1;
	}
	else if (c == 'E')
	{
		ray->dir[0] = 1;
		ray->dir[1] = 0;
	}
	else if (c == 'W')
	{
		ray->dir[0] = -1;
		ray->dir[1] = 0;
	}
	init_plane(ray, c);
}

void init_vectors(t_cub3d *cub3d)
{
	int i;
	int j;

	i = -1;
	while (cub3d->maps[++i])
	{
		j = -1;
		while (cub3d->maps[i][++j])
		{
			if (cub3d->maps[i][j] == 'N' || cub3d->maps[i][j] == 'S' || cub3d->maps[i][j] == 'E' || cub3d->maps[i][j] == 'W')
				init_player(i, j, cub3d->maps[i][j], cub3d->ray);
		}
	}
}
