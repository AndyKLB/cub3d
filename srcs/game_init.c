/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:37:09 by ankammer          #+#    #+#             */
/*   Updated: 2025/02/12 10:45:38 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int game_init(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init();
	if (!cub3d->mlx)
		msg_error("ERROR\nmlx_init failed", cub3d);
	cub3d->win = mlx_new_window(cub3d->mlx, WIN_W, WIN_H, "cub3d");
	if (!cub3d->win)
		msg_error("ERROR\nnew windows failed", cub3d);

	return (0);
}
int	handle_key_press(int keycode, t_cub3d *cub3d)
{
	if (keycode == XK_Escape)
		msg_error("Exit", cub3d);
	if (keycode == XK_w)
		cub3d->ray->move[Y] = 1;
	if (keycode == XK_s)
		cub3d->ray->move[Y] = -1;
	if (keycode == XK_a)
		cub3d->ray->move[X] = -1;
	if (keycode == XK_d)
		cub3d->ray->move[X] = 1;
	if (keycode == XK_Left)
		cub3d->ray->rotate = -1;
	if (keycode == XK_Right)
		cub3d->ray->rotate = 1;
	return (0);
}

int	handle_key_release(int keycode, t_cub3d *cub3d)
{
	if (keycode == XK_w)
		cub3d->ray->move[Y] = 0;
	if (keycode == XK_s)
		cub3d->ray->move[Y] = 0;
	if (keycode == XK_a)
		cub3d->ray->move[X] = 0;
	if (keycode == XK_d)
		cub3d->ray->move[X] = 0;
	if (keycode == XK_Left)
		cub3d->ray->rotate = 0;
	if (keycode == XK_Right)
		cub3d->ray->rotate = 0;
	return (0);
}

int	movedisplay(t_cub3d *cub3d)
{
	cub3d->ray->moved += moving(cub3d, cub3d->ray);
	if (cub3d->ray->moved == 0)
		return (1);
	raycasting(cub3d);
	return (0);
}