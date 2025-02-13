/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:33:42 by ankammer          #+#    #+#             */
/*   Updated: 2025/02/13 14:25:51 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	data_init(t_cub3d *cub3d, t_img *img, t_map *map, t_ray *ray)
{
	cub3d->map = map;
	cub3d->img = img;
	cub3d->ray = ray;
	init_cub3d_struct(&cub3d);
	init_map_struct(&map);
	init_img_struct(&img);
	init_ray_struct(&ray);
	return (0);
}

int	line_is_fullspace(char *line_map)
{
	size_t	i;

	i = 0;
	while (ft_isspace(line_map[i]))
		i++;
	if (i == ft_strlen(line_map))
		return (1);
	return (0);
}

int	line_is_spcnews(char *line_map)
{
	size_t	i;

	i = 0;
	while (ft_isspace(line_map[i]) || is_news(line_map[i]))
		i++;
	if (i == ft_strlen(line_map))
		return (1);
	return (0);
}
