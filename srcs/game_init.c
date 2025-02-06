/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:37:09 by ankammer          #+#    #+#             */
/*   Updated: 2025/02/06 15:32:53 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	game_init(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init();
	if (!cub3d->mlx)
		return (msg_error("mlxinit", cub3d));
	cub3d->win = mlx_new_window(cub3d->mlx, cub3d->win_width, cub3d->win_height,
			"cub3d");
	if (!cub3d->win)
		return (msg_error("mlxwin", cub3d));

	return (0);
}
