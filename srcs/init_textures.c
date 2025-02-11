/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:53:24 by wzeraig           #+#    #+#             */
/*   Updated: 2025/02/11 12:26:00 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
static void load_xpm(t_cub3d *cub3d, t_img *img, char *tex)
{
	img->mlx_img = mlx_xpm_file_to_image(cub3d->mlx, tex, &img->img_width,
										 &img->img_height);
	if (!img->mlx_img)
		msg_error("texture not found", cub3d);
	img->addr = (int *)mlx_get_data_addr(img->mlx_img, &img->bpp,
										 &img->line_len, &img->endian);
}

static int *get_tex(t_cub3d *cub3d, char *tex)
{
	t_img tmp;
	int *array;
	int x;
	int y;

	load_xpm(cub3d, &tmp, tex);
	array = ft_calloc(1, sizeof(int) * (IMG_SIZE * IMG_SIZE));
	if (!array)
		msg_error(ERR_MALLOC, cub3d);
	y = -1;
	while (++y < IMG_SIZE)
	{
		x = -1;
		while (++x < IMG_SIZE)
			array[y * IMG_SIZE + x] = tmp.addr[y * IMG_SIZE + x];
	}
	mlx_destroy_image(cub3d->mlx, tmp.mlx_img);
	return (array);
}


int	translate_color(int *rgb)
{
	int	color;

	color = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	return (color);
}
void init_textures(t_cub3d *cub3d)
{
	cub3d->textures = ft_calloc(5, sizeof(int *));
	if (!cub3d->textures)
		msg_error(ERR_MALLOC, cub3d);
	cub3d->textures[NORTH] = get_tex(cub3d, cub3d->north_element);
	cub3d->textures[SOUTH] = get_tex(cub3d, cub3d->south_element);
	cub3d->textures[WEST] = get_tex(cub3d, cub3d->west_element);
	cub3d->textures[EAST] = get_tex(cub3d, cub3d->east_element);
	cub3d->map->ccolor_i = translate_color(cub3d->map->c_tab);
	cub3d->map->fcolor_i = translate_color(cub3d->map->f_tab);
}