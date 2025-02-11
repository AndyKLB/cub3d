/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:14:57 by ankammer          #+#    #+#             */
/*   Updated: 2025/02/10 15:23:22 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int main(int argc, char **argv)
{
	t_cub3d cub3d;
	t_map map;
	t_img img;
	t_ray ray;

	if (argc == 2)
	{

		if (data_init(&cub3d, &img, &map, &ray))
			return (1);
		checkformat(&cub3d, argv[1]); // mettre les erreurs dans la fonction car il pourrait y avoir des erreur differente dans une seul fonction
		map_reader(&cub3d, argv[1]);
		checkmap(&cub3d);
		game_init(&cub3d);
		init_vectors(&cub3d);
		init_textures(&cub3d);
		raycasting(&cub3d);
		mlx_hook(cub3d.win, KeyPress, KeyPressMask, &handle_key_press, &cub3d);
		mlx_hook(cub3d.win, KeyRelease, KeyReleaseMask, &handle_key_release, &cub3d);
		mlx_hook(cub3d.win, DestroyNotify, 0, &free_cub3d, &cub3d);
		mlx_loop_hook(cub3d.mlx, &movedisplay, &cub3d);
		mlx_loop(cub3d.mlx);
	}
	return (0);
}

// print_data(&cub3d, 1);
// print_data(&cub3d, 0);
// printf("Map valid \n");
// printf("\xF0\x9F\x92\xA9\n");
// free_strs(cub3d.maps);
// cub3d.maps = NULL;