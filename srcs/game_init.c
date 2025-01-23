/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:37:09 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/23 14:44:35 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	get_win_size(t_cub3d *cub3d)
{
	int	i;

	if (!cub3d->maps || !cub3d->maps[0])
		return ;
	cub3d->win_width = ft_strlen(cub3d->maps[0]) * 32;
	i = 0;
	while (cub3d->maps[i])
		i++;
	cub3d->win_height = i * 32;
}

int	xpm_to_img(t_cub3d *cub3d)
{
	cub3d->img->wall_no = mlx_xpm_file_to_image(cub3d->mlx,
			cub3d->north_element, &cub3d->img->height, &cub3d->img->width);
	if (!cub3d->img->wall_no)
		return (1);
	cub3d->img->wall_so = mlx_xpm_file_to_image(cub3d->mlx,
			cub3d->south_element, &cub3d->img->height,
			&cub3d->img->width);
	if (!cub3d->img->wall_so)
		return (free(cub3d->img->wall_no), 1);
	cub3d->img->wall_ea = mlx_xpm_file_to_image(cub3d->mlx,
			cub3d->east_element, &cub3d->img->height,
			&cub3d->img->width);
	if (!cub3d->img->wall_ea)
		return (free(cub3d->img->wall_no), free(cub3d->img->wall_so), 1);
	cub3d->img->wall_we = mlx_xpm_file_to_image(cub3d->mlx,
			cub3d->west_element, &cub3d->img->height,
			&cub3d->img->width);
	if (!cub3d->img->wall_we)
		return (free(cub3d->img->wall_no), free(cub3d->img->wall_so),
			free(cub3d->img->wall_ea), 1); 
	// est ce qu'on dessine un player?
	// cub3d->img->player = mlx_xpm_file_to_image(cub3d->mlx,
	// 		cub3d->north_element, &cub3d->img->height,
	// 		&cub3d->img->width);
	// if (!cub3d->img->player)
	// 	return (free(cub3d->img->wall_no), free(cub3d->img->wall_so),
	// 		free(cub3d->img->wall_ea), free(cub3d->img->wall_we), 1);
	return (0);
}

void	draw_img(t_cub3d *cub3d, void *img, int x, int y)
{
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, img, x * 32, y * 32);
}

void	draw_map(t_cub3d *cub3d)
{
	int	y;
	int	x;

	y = 0;
	while (cub3d->maps[y])
	{
		x = 0;
		while (cub3d->maps[y][x])
		{
			if (cub3d->maps[y][x] == '1')
				// a voir comment faire pour les textures de chaque point cardinal
			{
				draw_img(cub3d, cub3d->img->wall_no, x, y);
				draw_img(cub3d, cub3d->img->wall_so, x, y);
				draw_img(cub3d, cub3d->img->wall_we, x, y);
				draw_img(cub3d, cub3d->img->wall_ea, x, y);
			}
			else if (is_character(cub3d->maps[y][x]))
				// pareil  pour la direction
				draw_img(cub3d, cub3d->img->player, x, y);
			else if (cub3d->maps[y][x] == '0')// comment dessiner le plafond et le sol ?
			{
				draw_img(cub3d, cub3d->img->floor, x, y);
				draw_img(cub3d, cub3d->img->celling, x, y);
			}
			x++;
		}
		y++;
	}
}

int	game_init(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init();
	if (!cub3d->mlx)
		return (1);
	cub3d->win = mlx_new_window(cub3d->mlx, cub3d->win_width, cub3d->win_height,
			"cub3d");
	if (!cub3d->win)
	{
		mlx_destroy_display(cub3d->mlx);
		free(cub3d->mlx);
		return (1);
	}
	if (xpm_to_img(cub3d))
	{
		mlx_destroy_window(cub3d->mlx, cub3d->win);
		mlx_destroy_display(cub3d->mlx);
		free(cub3d->mlx);
		return (1);
	}
	draw_map(cub3d);
	return (0);
}