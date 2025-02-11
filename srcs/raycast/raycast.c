/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:57:21 by wzeraig           #+#    #+#             */
/*   Updated: 2025/02/11 11:00:51 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RAPPEL le changer un jour avant le push ou le jour de la norme pour le header...
// CHANGES.
// bien commenter le code pour etre sur de ce que t'ecris.

#include "../../inc/cub3d.h"

static void	free_pixel_tab(int **buffer)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (i < WIN_H)
		i++;
	while (++j <= i)
		free(buffer[j]);
	free(buffer);
}

static void	img_addr(t_cub3d *cub3d, int **buffer, int i)
{
	int		j;
	int		index;
	t_img	img;

	img.mlx_img = mlx_new_image(cub3d->mlx, WIN_W, WIN_H);
	img.addr = (int *)mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len,
			&img.endian);
	while (++i < WIN_H)
	{
		j = -1;
		while (++j < WIN_W)
		{
			index = i * (img.line_len / 4) + j;
			if (buffer[i][j] > 0)
				img.addr[index] = buffer[i][j];
			else if (i < WIN_H / 2)
				img.addr[index] = cub3d->map->ccolor_i;
			else
				img.addr[index] = cub3d->map->fcolor_i;
		}
	}
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, img.mlx_img, 0, 0);
	mlx_destroy_image(cub3d->mlx, img.mlx_img);
}

static void	ray_loop(t_cub3d *cub3d, t_ray *ray, int **buf)
{
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		initialize_ray_direction(ray, x);
		calculate_initial_side_distances(ray);
		perform_dda(cub3d, ray);
		initialize_wall_draw(ray);
		render_wall_pixels(cub3d, ray, x, buf);
		x++;
	}
	img_addr(cub3d, buf, -1);
	free_pixel_tab(buf);
}

void	raycasting(t_cub3d *cub3d)
{
	int	i_buf;
	int	**buf;

	i_buf = 0;
	buf = ft_calloc(WIN_H + 1, sizeof(int *));
	if (!buf)
		msg_error(ERR_MALLOC, cub3d);
	while (i_buf <= WIN_H)
	{
		buf[i_buf] = ft_calloc(WIN_W + 1, sizeof(int));
		if (!buf[i_buf])
		{
			while (i_buf >= 0)
			{
				free(buf[i_buf]);
				i_buf--;
			}
			free(buf);
			msg_error(ERR_MALLOC, cub3d);
		}
		i_buf++;
	}
	ray_loop(cub3d, cub3d->ray, buf);
}

