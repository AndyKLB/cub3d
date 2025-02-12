/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:14:57 by ankammer          #+#    #+#             */
/*   Updated: 2025/02/12 13:33:59 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;
	t_map	map;
	t_img	img;
	t_ray	ray;

	if (argc == 2)
	{
		if (data_init(&cub3d, &img, &map, &ray))
			return (1);
		checkformat(&cub3d, argv[1]);
		map_reader(&cub3d, argv[1]);
		checkmap(&cub3d);
		game_init(&cub3d);
		init_vectors(&cub3d);
		init_textures(&cub3d);
		raycasting(&cub3d);
		mlx_hook(cub3d.win, KeyPress, KeyPressMask, &handle_key_press, &cub3d);
		mlx_hook(cub3d.win, KeyRelease, KeyReleaseMask, &handle_key_release,
			&cub3d);
		mlx_hook(cub3d.win, DestroyNotify, 0, &free_cub3d, &cub3d);
		mlx_loop_hook(cub3d.mlx, &movedisplay, &cub3d);
		mlx_loop(cub3d.mlx);
	}
	return (0);
}
